#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

void sieve(char *current, struct dirent **sieved, int *sieved_sz) {
    DIR *path = opendir(current);

    if (path == NULL) {
        return;
    }

    int c, f, d, files_sz, directories_sz, combined_sz;
    struct dirent *file, **files, **directories;

    files_sz = directories_sz = combined_sz = 8;

    files = malloc(files_sz * sizeof(struct dirent *));
    directories = malloc(directories_sz * sizeof(struct dirent *));
    
    f = d = 0;
    while ((file = readdir(path)) != NULL) {
        if (f >= files_sz) {
            files_sz *= 2;
            files = realloc(files, files_sz * sizeof(struct dirent *));
        }
        if (d >= directories_sz) {
            directories_sz *= 2;
            directories = realloc(directories, directories_sz * sizeof(struct dirent *));
        }
        if (strcmp(file->d_name, ".") == 0)
            continue;
        if (strcmp(file->d_name, "..") == 0)
            continue;
        if (file->d_type == DT_DIR)
            directories[d++] = file;
        else
            files[f++] = file;
    }

    for (int i = 0; i < d; ++i) {
        if (i > combined_sz) {
            combined_sz *= 2;
            sieved = realloc(sieved, combined_sz * sizeof(struct dirent *));
        }
        sieved[i] = directories[i];
    }

    for (int i = 0; i < f; ++i) {
        if ((i+d) > combined_sz) {
            combined_sz *= 2;
            sieved = realloc(sieved, combined_sz * sizeof(struct dirent *));
        }
        sieved[i+d] = files[i];
    }

    *sieved_sz = f + d;

    free(files);
    free(directories);
}

void print_parent_prefix(int depth, bool is_parent_last) {
    if (is_parent_last) {
        for (int i = 0; i < depth-1; ++i)
            printf("┃ ");
        printf("  ");               
    } else {
        for (int i = 0; i < depth; ++i)
            printf("┃ ");
    }
}

void traverse(char *current, int depth, bool is_parent_last) {
    int sieved_sz;
    struct dirent **sieved;
    
    sieved_sz = 256;

    sieved = malloc(sieved_sz * sizeof(struct dirent *));
    sieve(current, sieved, &sieved_sz);

    for (int i = 0; i < sieved_sz; ++i) {
        bool is_last = i + 1 == sieved_sz;
        const char *filename_prefix = is_last ? "┗━" : "┣━";
        
        print_parent_prefix(depth, is_parent_last);
   
        if (sieved[i]->d_type == DT_DIR) {
            printf("%s %s\n", filename_prefix, sieved[i]->d_name);
            
            char spam[PATH_MAX];
            snprintf(spam, PATH_MAX, "%s/%s", current, sieved[i]->d_name);
            traverse(spam, depth+1, is_last);
        } else {
            printf("%s %s\n", filename_prefix, sieved[i]->d_name);
        }
    }

    free(sieved);
}

int main(int argc, char *argv[]) {
    traverse(argv[1], 0, false);
}