typedef enum {
  NO_ERROR,
  NULL_ERRORS,
  OUT_OF_BOUNDS
} Error;


void replaceChar(char *s, char oldChar, char newChar);


char * replaceCharCopy(const char *s, char oldChar, char newChar);


void removeChar(char *s, char c);


char * removeCharCopy(const char *s, char c);


char **lengthSplit(const char *s, int n);
