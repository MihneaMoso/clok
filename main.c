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

const int ext_len = sizeof(extensions) / sizeof(extensions[0]);
static size_t *extensions_counts = NULL;

void init_extensions_counts() {
     extensions_counts = (size_t*) malloc(ext_len * sizeof(size_t));
}

void print_usage(char* program) {
    printf("Usage: %s [DIRECTORY]\nCount the lines of code in a directory\n", program);
}

void print_summary() {
    printf("\nLines of Kode Summary: \n");

    for (size_t i = 0; i < ext_len; ++i) {
        if (extensions_counts[i] != 0) {
            printf("Index %zu has %zu lines of code.\n", i, extensions_counts[i]);
        }
    }
}

void print_thing(const char* path) {
    printf(" -- The file is %s\n", path);
}

int get_extension_index(const char* string) {
    
    String_View s = sv(string);
    String_View filename = sv_chop_by_delim(&s, '.', true);
    const char* ext = s.data;

    for (size_t i = 0; i < ext_len; ++i) {
        if (strcmp(ext, extensions[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void increment_extension_count(const char* ext, size_t count) {
    int index = get_extension_index(ext);
    if (index == -1) return;
    extensions_counts[index] += count;
}

size_t count_lines(String_View *sv) {
    size_t count = 0;
    
    while (sv->count > 0) {
        String_View line = sv_chop_by_delim(sv, '\n', false);
        sv_trim(&line);
        if (line.count > 0) count += 1; // ignore empty lines
    }
    return count;
}

void read_and_increment(const char* path) {

    String_Builder sb = {0};
    if (!read_entire_file(path, &sb)) return;

    String_View s = {
        .data = sb.items,
        .count = sb.count,
    };
    
    size_t count = count_lines(&s); // number of loc
    increment_extension_count(path, count);

    free(sb.items);
}

void walk_dir(const char* dirpath, void (*walker_fn) (const char* path)) {
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

    init_extensions_counts();

    walk_dir(dir, read_and_increment);
    print_summary();
    free(extensions_counts);
    
    return 0;
}
