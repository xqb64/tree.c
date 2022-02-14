#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>

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

struct dirent *superscalar_readdir(DIR *path) {
    while (true) {
        struct dirent *p = readdir(path);
        if (!p) return NULL;
        if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0) continue;
        return p;
    }
}

void traverse(char *current, int depth, bool is_parent_last) {
    int sieved_sz;
    struct dirent *file, *next;
    DIR *path;
    
    sieved_sz = 256;
    path = opendir(current);
    file = superscalar_readdir(path);
    next = superscalar_readdir(path);

    for (; file; file = next, next = superscalar_readdir(path)) {
        bool is_last = next == NULL;
        const char *filename_prefix = is_last ? "┗━" : "┣━";
        
        print_parent_prefix(depth, is_parent_last);
   
        if (file->d_type == DT_DIR) {
            printf("%s %s\n", filename_prefix, file->d_name);
            
            char spam[PATH_MAX];
            snprintf(spam, PATH_MAX, "%s/%s", current, file->d_name);
            traverse(spam, depth+1, is_last);
        } else {
            printf("%s %s\n", filename_prefix, file->d_name);
        }
    }

    closedir(path);
}

int main(int argc, char *argv[]) {
    traverse(argv[1], 0, false);
}