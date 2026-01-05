#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pnger.h"

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "--file-path") != 0) {
        printf("you did it worng here is the correct way: %s --file-path <path_to_file>\n", argv[0]);
        return 1;
    }
    
    char *filePath = argv[2];

    FILE *fp = fopen(filePath, "rb");

    if (fp == NULL) {
        printf("couldnt open it ... maybe the path is wrong?\n");
        return 1;
    }
    
    if (is_png(fp)) {
        printf(" this file is a PNG!\n");
    } else {
        printf(" this ain't a PNG file.\n");
    }
    
    fclose(fp);
    
    return 0;
}
