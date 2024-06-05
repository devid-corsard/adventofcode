#include <stdio.h>
#include <stdlib.h>

#define INPUT_SZ 40 * 1024

typedef struct {
    char data[INPUT_SZ];
} AOCInput;

AOCInput read_file_to_string(char *filename);
