#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "assert.h"
#include <stdarg.h>
#include "print.h"
#include "da.h"
#include "sb.h"
#include "sv.h"
#include "util.h"
#include "extensions.h"

#ifdef _WIN32
    #define PATH_SEP "\\"
#else
    #define PATH_SEP "/"
#endif

// #define PATH_MAX 256

void print_usage(char* program) {
    printf("Usage: %s [DIRECTORY]\nCount the lines of code in a directory\n", program);
}

int print_thing(const char* path) {
    printf(" -- The file is %s\n", path);
    return 0;
}

int get_extension(const char* string) {
    const int ext_len = sizeof(extensions) / sizeof(extensions[0]);
    
    String_View s = sv(string);
    String_View filename = sv_chop_by_delim(&s, '.', true);
    const char* ext = s.data;

    for (size_t i = 0; i < ext_len; ++i) {
        if (strcmp(ext, extensions[i]) == 0) {
            return i;
        }
    }
    return NULL;
}

void walk_dir(const char* dirpath, int (*walker_fn) (const char* path)) {
    DIR* dirp = opendir(dirpath);
    if (dirp == NULL) return;

    struct dirent* root;
    
    while ((root = readdir(dirp)) != NULL) {
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s"PATH_SEP"%s", dirpath, root->d_name);

        switch (root->d_type) {
            case DT_REG: {
                // printf("%s is a regular file.\n", root->d_name);
                walker_fn(fullpath);
                break;
            }
            case DT_DIR: {
                char* name = root->d_name;
                if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
                    continue;
                }
                // walker_fn(name);
                // printf("Going to %s\n", name);

                walk_dir(fullpath, walker_fn);
                
                break;
            }
            case DT_BLK:
            case DT_CHR:
            case DT_FIFO:
            case DT_LNK:
            case DT_SOCK:
            case DT_UNKNOWN:
                break;
       }
    }
    
    int ret = closedir(dirp);
    if (ret != 0) {
        char *error = strerror(errno);
        printf("Closing directory unsuccessful, error: %s\n", error);
    }
}


int main(int argc, char** argv) {
    
    char* dir;
    
    if (argc == 1) {
        dir = ".";
    } else if (argc == 2) {
        dir = argv[1];
        
    } else {
        print_usage(argv[0]);
        exit(1);
    }
    
    if (strlen(dir) >= 256) {
        printf("Please provide a directory with maximum %d length.\n", PATH_MAX);
        return 1;
    }
    // printf("dir = %s\n", dir);
    // DIR* dirp = opendir(dir);
    
    // struct dirent *dir_entity;
    // while ((dir_entity = readdir(dirp)) != NULL) {
    //     printf("name = %s, type = %c\n", dir_entity->d_name, dir_entity->d_type);
    // }
    walk_dir(dir, print_thing);
    
    return 0;
}
