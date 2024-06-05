#include "../utils/readfile.h"
#include <stdio.h>
#include <string.h>

int neigs_contain_symbol(int *coords, size_t coords_len, char *input, char lookup) {
    for (size_t i = 0; i < coords_len; i++) {
        int crd = coords[i];
        char ch = input[crd];

        if (crd > 0 && (size_t)crd <= strlen(input) && ch != lookup && ch != '\n') {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    AOCInput input;
    char *filename;
    char number[4];
    int number_len = 0, answer = 0, width = 0;

    filename = argc == 2 ? argv[1] : "sample.txt";
    input = read_file_to_string(filename);

    while (input.data[width] != '\n') {
        width++;
    }
    width++;
    printf("Width: %d\n", width);

    for (size_t i = 0; i < strlen(input.data); i++) {
        if (input.data[i] >= 0x30 && input.data[i] <= 0x39) {
            number[number_len] = input.data[i];
            number_len++;
        } else {
            if (number_len > 3)
                fputs("0 or 3+ digits", stderr), exit(1);

            if (!number_len)
                continue;

            int ncoords[12] = {
                i,
                i - width,
                i + width,
                i - (number_len + 1),
                i - (number_len + 1) - width,
                i - (number_len + 1) + width,
            };

            for (int k = 6, sh = 1; k < 6 + (2 * number_len); k = k + 2, sh++) {
                ncoords[k] = i - sh - width;
                ncoords[k + 1] = i - sh + width;
            }

            int ncoords_len = 6 + (2 * number_len);

            if (neigs_contain_symbol(ncoords, ncoords_len, input.data, '.')) {
                number[number_len] = '\0';
                answer += atoi(number);
            }

            number_len = 0;
        }
    }

    printf("Answer: %d", answer);
    return 0;
}
