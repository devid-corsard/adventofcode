#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

// allocates memory
char *read_file_to_string(char *filename) {
    FILE *fp;
    long lSize;
    char *buffer;

    fp = fopen(filename, "rb");
    if (!fp)
        perror(filename), exit(1);

    fseek(fp, 0L, SEEK_END);
    lSize = ftell(fp);
    rewind(fp);

    buffer = (char*)calloc(1, lSize + 1);
    if (!buffer)
        fclose(fp), fputs("memory alloc fails", stderr), exit(1);

    if (1 != fread(buffer, lSize, 1, fp))
        fclose(fp), free(buffer), fputs("entire read fails", stderr), exit(1);

    fclose(fp);
    return buffer;
}
