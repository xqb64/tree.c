#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>

void print_parent_prefix(int depth, bool is_parent_last) {
    int adjusted_depth = is_parent_last ? depth - 1 : depth;
    for (int i = 0; i < adjusted_depth; ++i)
        printf("┃ ");
    if (is_parent_last)
        printf("  ");               
}

struct dirent *superscalar_readdir(DIR *path) {
    /* 
     * Since readdir(3) returns both "." and "..", we need readdir-like
     * function that will read the directory and return everything except
     * "." and "..". Otherwise, one of "." or ".." may be read last which
     * breaks the code that checks if an entry is the last entry in the dir.
     */
    while (true) {
        struct dirent *p = readdir(path);
        if (!p) return NULL;
        if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0) continue;
        return p;
    }
}

void traverse(
    char *current,
    bool exclude_hidden_files,
    int depth,
    bool is_parent_last
) {
    DIR *path;
    struct dirent *file, *next;
    
    path = opendir(current);
    file = superscalar_readdir(path);
    next = superscalar_readdir(path);

    for (; file; file = next, next = superscalar_readdir(path)) {
        if (exclude_hidden_files && strncmp(file->d_name, ".", 1) == 0)
            continue;
        
        bool is_last = next == NULL;
        const char *filename_prefix = is_last ? "┗━" : "┣━";
        
        print_parent_prefix(depth, is_parent_last);
   
        if (file->d_type == DT_DIR) {
            printf("%s %s\n", filename_prefix, file->d_name);
            
            char buf[PATH_MAX];
            snprintf(buf, PATH_MAX, "%s/%s", current, file->d_name);
            traverse(buf, exclude_hidden_files, depth+1, is_last);
        } else {
            printf("%s %s\n", filename_prefix, file->d_name);
        }
    }

    closedir(path);
}

int main(int argc, char *argv[]) {
    bool exclude_hidden_files = false;

    if (argv[2]) 
        exclude_hidden_files = strcmp(argv[2], "-e") == 0;

    traverse(argv[1], exclude_hidden_files, 0, false);
}