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
#include "util.h"

void print_usage(char* program) {
    printf("Usage: %s [DIRECTORY]\nCount the lines of code in a directory\n", program);
}

int print_thing(const char* path) {
    printf(" -- The directory is %s\n", path);
    return 0;
}

void walk_dir(DIR* dirp, int (*walker_fn) (const char* path)) {
    struct dirent* root;
    
    while ((root = readdir(dirp)) != NULL) {
        switch (root->d_type) {
            case DT_REG: {
                printf("%s is a regular file.\n", root->d_name);
                walker_fn(root->d_name);
                break;
            }
            case DT_DIR: {
                char* name = root->d_name;
                if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
                    continue;
                }
                DIR* newdir = opendir(name);
                if (newdir != NULL) {
                    walker_fn(name);

                    walk_dir(newdir, walker_fn);
                }
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
    
    // printf("dir = %s\n", dir);
    DIR* dirp = opendir(dir);
    
    // struct dirent *dir_entity;
    // while ((dir_entity = readdir(dirp)) != NULL) {
    //     printf("name = %s, type = %c\n", dir_entity->d_name, dir_entity->d_type);
    // }
    walk_dir(dirp, print_thing);
    
    int ret = closedir(dirp);
    if (ret != 0) {
        char *error = strerror(errno);
        printf("Closing directory unsuccessful, error: %s\n", error);
    }
    
    return 0;
}
