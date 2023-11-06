#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "file_utils.h"



char *getFileContents(const char *filePath) {

    FILE *contents = fopen(filePath, "r");
    if(contents == NULL){
        return NULL;
    }

    int counter = 0;
    while(fgetc(contents) != EOF){
        counter++;
    }
    fclose(contents);
    contents = fopen(filePath, "r");

    char *newString = (char *)malloc(sizeof(char *) * counter + 1);
    for(int i = 0; i < counter; i++){
        newString[i] = fgetc(contents);
    }

    newString[counter] = '\0';

    fclose(contents);

    return newString;
}


char **getFileLines(const char *filePath, int *numLines) {
    FILE *contents = fopen(filePath, "r");

    char c = fgetc(contents);
    int counter = 0;
    int buffer = 0;
    int buffer2 = 0;
    for(c = getc(contents); c != EOF; c = getc(contents)){
        if (c == '\n'){
            counter++;
            if(buffer < buffer2){
                buffer = buffer2;
            }
        }
        buffer2++;
    }

    fclose(contents);
    contents = fopen(filePath, "r");


    char **newString = (char **)malloc(sizeof(char *) * counter);
    for(int i = 0; i < counter; i++){
        newString[i] = (char *)malloc(sizeof(char*) * buffer);
    }

    for(int i = 0; i < counter; i++){
        fgets(newString[i], buffer, contents);
        newString[i][strlen(newString[i]) - 1] = '\0';
    }

    fclose(contents);

    *numLines = counter;
    return newString;
}
