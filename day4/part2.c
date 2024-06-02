#include <stdio.h>
#include <string.h>

#include "../readfile.h"

// #define IS_SAMPLE 1

#ifndef IS_SAMPLE
#define WW 10
#define MM 25
#define CARDS 218
#endif

#ifdef IS_SAMPLE
#define WW 5
#define MM 8
#define CARDS 6
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
            #ifndef IS_SAMPLE
            int res = sscanf(line,
                             "Card %*d: %d %d %d %d %d %d %d %d %d %d | %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                             &win_nums[0],
                             &win_nums[1],
                             &win_nums[2],
                             &win_nums[3],
                             &win_nums[4],
                             &win_nums[5],
                             &win_nums[6],
                             &win_nums[7],
                             &win_nums[8],
                             &win_nums[9],
                             &my_nums[0],
                             &my_nums[1],
                             &my_nums[2],
                             &my_nums[3],
                             &my_nums[4],
                             &my_nums[5],
                             &my_nums[6],
                             &my_nums[7],
                             &my_nums[8],
                             &my_nums[9],
                             &my_nums[10],
                             &my_nums[11],
                             &my_nums[12],
                             &my_nums[13],
                             &my_nums[14],
                             &my_nums[15],
                             &my_nums[16],
                             &my_nums[17],
                             &my_nums[18],
                             &my_nums[19],
                             &my_nums[20],
                             &my_nums[21],
                             &my_nums[22],
                             &my_nums[23],
                             &my_nums[24]);
            #endif
            #ifdef IS_SAMPLE
            int res = sscanf(line,
                             "Card %*d: %d %d %d %d %d | %d %d %d %d %d %d %d %d",
                             &win_nums[0],
                             &win_nums[1],
                             &win_nums[2],
                             &win_nums[3],
                             &win_nums[4],
                             &my_nums[0],
                             &my_nums[1],
                             &my_nums[2],
                             &my_nums[3],
                             &my_nums[4],
                             &my_nums[5],
                             &my_nums[6],
                             &my_nums[7]);
            #endif

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
        printf("Copies: %d\n", copies[i]);
        answer += copies[i];
    }

    printf("Answer: %d\n", answer);
    free(input);
    return 0;
}
