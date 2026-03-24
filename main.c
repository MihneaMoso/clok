#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "assert.h"

void print_usage(char* program) {
    printf("Usage: %s [DIRECTORY]\nCount the lines of code in a directory\n", program);
}

bool read_entire_file(const char *path, String_Builder *sb)
{
    FILE *f = fopen(path, "rb");
    size_t new_count = 0;
    long long m = 0;
    if (f == NULL)                 goto fail;
    if (fseek(f, 0, SEEK_END) < 0) goto fail;
#ifndef _WIN32
    m = ftell(f);
#else
    m = _ftelli64(f);
#endif
    if (m < 0)                     goto fail;
    if (fseek(f, 0, SEEK_SET) < 0) goto fail;

    new_count = sb->count + m;
    if (new_count > sb->capacity) {
        sb->items = realloc(sb->items, new_count);
        assert(sb->items != NULL && "Buy more RAM lool!!");
        sb->capacity = new_count;
    }

    fread(sb->items + sb->count, m, 1, f);
    if (ferror(f)) {
        // TODO: Afaik, ferror does not set errno. So the error reporting in fail is not correct in this case.
        goto fail;
    }
    sb->count = new_count;

    fclose(f);
    return true;
fail:
    fprintf(stderr, "ERROR: Could not read file %s: %s\n", path, strerror(errno));
    if (f) fclose(f);
    return false;
}

void walk_dir(char* root, int (*walker_fn) (char* path)) {
    
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
    // printf("dirp = %p\n", dirp);
    
    
    struct dirent *dir_entity;
    while ((dir_entity = readdir(dirp)) != NULL) {
        printf("name = %s, type = %c\n", dir_entity->d_name, dir_entity->d_type);
    }
    
    int ret = closedir(dirp);
    if (ret != 0) {
        char *error = strerror(errno);
        printf("Closing directory unsuccessful, error: %s\n", error);
    }
    
    return 0;
}