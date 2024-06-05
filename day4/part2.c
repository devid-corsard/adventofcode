#include <stdio.h>
#include <string.h>

#include "../readfile.h"

// #define IS_SAMPLE

#ifdef IS_SAMPLE

#define WW 5
#define MM 8
#define CARDS 6
#define P_STR "Card %*d: %d %d %d %d %d | %d %d %d %d %d %d %d %d"
#define ARS(A,B) &A[0], &A[1], &A[2], &A[3], &A[4], &B[0], &B[1], &B[2], &B[3], &B[4], &B[5], &B[6], &B[7]

#else 

#define WW 10
#define MM 25
#define CARDS 218
#define P_STR "Card %*d: %d %d %d %d %d %d %d %d %d %d | %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d"
#define ARS(A,B) &A[0], &A[1], &A[2], &A[3], &A[4], &A[5], &A[6], &A[7], &A[8], &A[9], &B[0], &B[1], &B[2], &B[3], &B[4], &B[5], &B[6], &B[7], &B[8], &B[9], &B[10], &B[11], &B[12], &B[13], &B[14], &B[15], &B[16], &B[17], &B[18], &B[19], &B[20], &B[21], &B[22], &B[23], &B[24]

#endif

int
main(int argc, char** argv)
{
    char *filename, *input;
    int answer = 0, width = 0, cardn=1;
    int win_nums[WW], my_nums[MM];
    size_t line_pos = 0;
    int copies[CARDS]={[0 ... CARDS-1] = 1};

    filename = argc == 2 ? argv[1] : "sample.txt";
    input = read_file_to_string(filename);

    while (input[width] != '\n') {
        width++;
    }
    width++;
    printf("Width: %d\n", width);
    char line[width];

    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] != '\n') {
            line[line_pos++] = input[i];
        } else {
            line[line_pos] = '\0';
            line_pos = 0;

            int res = sscanf(line, P_STR, ARS(win_nums, my_nums));

            if (res != WW+MM) {
                fprintf(stderr, "Failed to parse the line correctly. parsed: %d line: %s\n",
                                                                             res,     line);
                return 1;
            }
            size_t matches = 0;
            for (size_t i=0;i<WW;i++){ for (size_t j=0;j<MM;j++){
                    if (win_nums[i]==my_nums[j]) matches++;
                } }
            if (matches>0) { for (size_t m = cardn; m <= cardn-1 + matches; m++) {
                    copies[m] += copies[cardn-1];
                } }
            matches = 0;
            cardn++;
        }
    }
    for (size_t i = 0; i < CARDS; i++){
        answer += copies[i];
    }

    printf("Answer: %d\n", answer);
    free(input);
    return 0;
}
