#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "string_utils.h"


void replaceChar(char *s, char oldChar, char newChar){

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == oldChar){
            s[i] = newChar;
        }
    }
}


char * replaceCharCopy(const char *s, char oldChar, char newChar){

    if(s == NULL || oldChar < 0 || newChar < 0){
        return NULL;
    }

    char* newString = malloc(strlen(s));

     for(int i = 0; i < strlen(s); i++){
        if(s[i] == oldChar){
            newString[i] = newChar;
        } else {
            newString[i] = s[i];
        }
    }
    return newString;
}


void removeChar(char *s, char c){
    int counter = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == c){
            counter++;
            s[i] = s[s + counter];
            i--;
        }
        else {
            s[i] = s[i + counter];
        }
    }
}



char * removeCharCopy(const char *s, char c){

    if(s == NULL || c < 0){
        return NULL;
    }

    char* newString = malloc(strlen(s));
    int counter = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] != c){
            newString[i] = s[i + counter];
        } else {
            counter++;
            i--;
        }
    }
    return newString;
}


char **lengthSplit(const char *s, int n){

    if(s == NULL || n < 0){
        return NULL;
    }
    char **newString;
    if(strlen(s) % n != 0){
        newString = malloc(((strlen(s)+n)/n) * n);
    } else {
        newString = malloc((strlen(s)/n) * n);
    }
    int counter1 = 0;
    int counter2 = 0;

    for(int i = 0; i < strlen(s); i++){
        if(counter1 == (n-1)){
            counter1 = 0;
            counter2++;
        }
        newString[counter2][counter1] = s[i];
        counter1++;
    }
    return newString;

}
