#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

// allocates memory
AOCInput read_file_to_string(char *filename) {
    FILE *fp;
    long lSize;
    AOCInput buffer;

    fp = fopen(filename, "rb");
    if (!fp)
        perror(filename), exit(1);

    fseek(fp, 0L, SEEK_END);
    lSize = ftell(fp);
    rewind(fp);

    if (1 != fread(&buffer.data, lSize, 1, fp))
        fclose(fp), fputs("entire read fails", stderr), exit(1);

    fclose(fp);
    return buffer;
}
