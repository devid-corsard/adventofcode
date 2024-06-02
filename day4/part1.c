#include <stdio.h>
#include <string.h>

#include "../readfile.h"

int
main(int argc, char** argv)
{
    char *filename, *input;
    int answer = 0, width = 0;
    int win_nums[10], my_nums[25];
    size_t line_pos = 0;

    filename = argc == 2 ? argv[1] : "sample.txt";
    input = read_file_to_string(filename);

    while (input[width] != '\n') {
        width++;
    }
    width++;
    printf("Width: %d\n", width);
    char line[width];

    // TODO:
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] != '\n') {
            line[line_pos++] = input[i];
        } else {
            line[line_pos] = '\0';
            line_pos = 0;
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

            if (res != 35) {
                fprintf(
                  stderr, "Failed to parse the line correctly. parsed: %d line: %s\n", res, line);
                return 1;
            }
            int matches = 0;
            for (size_t i=0;i<10;i++){ for (size_t j=0;j<25;j++){
                    if (win_nums[i]==my_nums[j]) matches++;
                } }
            if (matches>0) answer += 1 << (matches - 1);
            matches = 0;
        }
    }

    printf("Answer: %d\n", answer);
    free(input);
    return 0;
}
