#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "file_utils.h"

char *length;

char *getFileContents(const char *filePath) {

    FILE *current = fopen(filePath, "r");

    if(filePath == NULL) {
        return NULL;
    }

    fseek(current, 0, SEEK_END);

    while (feof(current) != 1) {
        fread(length, sizeof(length), 1, current);
    }

    fclose(current);

    return length;
}


char **getFileLines(const char *filePath, int *numLines) {


    char **files = (char **)malloc(sizeof(char *) * *numLines);
    for (int i = 0; i < *numLines; i++) {
        files[i] = (char *)malloc(sizeof(char) * sizeof(length));
    }

    FILE *current = fopen(filePath, "r");

    if( filePath == NULL || numLines == NULL) {
        return NULL;
    }

    int i = 0;
    while(fscanf(current, "%s", length) == 1) {
        strcpy(files[i], length);
        i++;
    }
    fclose(current);
    return files;
}
