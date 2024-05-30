#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../readfile.h"

int main(int argc, char **argv) {
    char *filename, *input;
    size_t token_length = 0;
    char token[10], digital_token[10];
    int red_max, green_max, blue_max, sum_of_powers = 0;

    filename = argc == 2 ? argv[1] : "sample.txt";
    input = read_file_to_string(filename);

    for (size_t i = 0; i < strlen(input); i++) {
        char cur = input[i];

        if (cur == ' ' || cur == '\n') {
            token[token_length] = '\0';

            if (token[0] == 'G') {
                sum_of_powers += green_max * blue_max * red_max;
                red_max = green_max = blue_max = 0;

            } else if (token[0] == 'r') {
                int n = atoi(digital_token);
                red_max = n > red_max ? n : red_max;

            } else if (token[0] == 'g') {
                int n = atoi(digital_token);
                green_max = n > green_max ? n : green_max;

            } else if (token[0] == 'b') {
                int n = atoi(digital_token);
                blue_max = n > blue_max ? n : blue_max;

            } else {
                strcpy(digital_token, token);
            }

            token_length = 0;
        } else {
            token[token_length] = cur;
            token_length++;
        }
    }

    sum_of_powers += green_max * blue_max * red_max;

    free(input);

    printf("Answer %d\n", sum_of_powers);

    return 0;
}
