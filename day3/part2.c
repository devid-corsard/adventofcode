#include "../readfile.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    bool result;
    size_t coord_of_gear;
} CheckRes;

CheckRes neigs_contain_lookup(size_t *coords, size_t coords_len, char *input, char lookup) {
    for (size_t i = 0; i < coords_len; i++) {
        size_t crd = coords[i];
        char ch = input[crd];

        if (crd > 0 && crd <= strlen(input) && ch == lookup) {
            return (CheckRes){true, crd};
        }
    }

    return (CheckRes){false, 0};
}

int main(int argc, char **argv) {
    char *filename, *input;
    char number[4];
    int number_len = 0, answer = 0, width = 0;
    char nums1[20000][4] = {0};
    memset(nums1, '\0', sizeof(nums1));
    char nums2[20000][4] = {0};
    memset(nums2, '\0', sizeof(nums1));

    filename = argc == 2 ? argv[1] : "sample.txt";
    input = read_file_to_string(filename);

    while (input[width] != '\n') {
        width++;
    }
    width++;
    printf("Width: %d\n", width);

    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] >= 0x30 && input[i] <= 0x39) {
            number[number_len] = input[i];
            number_len++;
        } else {
            if (number_len > 3)
                fputs("0 or 3+ digits", stderr), exit(1);

            if (!number_len)
                continue;

            size_t ncoords[12] = {
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

            CheckRes res = neigs_contain_lookup(ncoords, ncoords_len, input, '*');

            if (res.result) {
                number[number_len] = '\0';

                if (nums1[res.coord_of_gear][0] == '\0' && nums1[res.coord_of_gear][0] != 'k') {
                    strcpy(nums1[res.coord_of_gear], number);
                } else if (nums2[res.coord_of_gear][0] == '\0' &&
                           nums2[res.coord_of_gear][0] != 'k') {
                    strcpy(nums2[res.coord_of_gear], number);
                    answer += atoi(nums1[res.coord_of_gear]) * atoi(number); // there was no more than 2 so its enough
                } else {
                    strcpy(nums1[res.coord_of_gear], "kek");
                    strcpy(nums2[res.coord_of_gear], "kek");
                }
            }

            number_len = 0;
        }
    }

    printf("Answer: %d", answer);
    free(input);
    return 0;
}
