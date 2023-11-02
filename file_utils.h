typedef enum {
  NO_ERROR,
  NULL_ERRORS,
  OUT_OF_BOUNDS
} Error;


char *getFileContents(const char *filePath);


char **getFileLines(const char *filePath, int *numLines);
