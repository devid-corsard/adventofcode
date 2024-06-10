#include <stdio.h>
#include <string.h>

#include "../utils/readfile.h"

typedef enum
{
    START,
    SEEDS,
    SEED_TO_SOIL,
    SOIL_TO_FERTILIZER,
    FERTILIZER_TO_WATER,
    WATER_TO_LIGHT,
    LIGHT_TO_TEMPERATURE,
    TEMPERATURE_TO_HUMIDITY,
    HUMIDITY_TO_LOCATION,
    STAGES_LEN,
} Stage;

int
set_stage(Stage* s, const char* t)
{
    if (strcmp(t, "seeds:") == 0) {
        *s = SEEDS;
    } else if (strcmp(t, "seed-to-soil") == 0) {
        *s = SEED_TO_SOIL;
    } else if (strcmp(t, "soil-to-fertilizer") == 0) {
        *s = SOIL_TO_FERTILIZER;
    } else if (strcmp(t, "fertilizer-to-water") == 0) {
        *s = FERTILIZER_TO_WATER;
    } else if (strcmp(t, "water-to-light") == 0) {
        *s = WATER_TO_LIGHT;
    } else if (strcmp(t, "light-to-temperature") == 0) {
        *s = LIGHT_TO_TEMPERATURE;
    } else if (strcmp(t, "temperature-to-humidity") == 0) {
        *s = TEMPERATURE_TO_HUMIDITY;
    } else if (strcmp(t, "humidity-to-location") == 0) {
        *s = HUMIDITY_TO_LOCATION;
    } else {
        if (strcmp(t, "map:") != 0) {
            return 0;
        }
    }
    return 1;
}

void
fill_map(long map[100][3], size_t* map_row, size_t* map_col, char* t)
{
    map[*map_row][(*map_col)++] = atol(t);
    if (*map_col > 2) {
        *map_col = 0;
        (*map_row)++;
    }
}

void
calculate_dest(long map[100][3], size_t map_row, long seeds[20], size_t seeds_sz)
{
    printf("Map:\n");
    for (size_t r = 0; r < map_row; r++) {
        printf("%ld %ld %ld\n", map[r][0], map[r][1], map[r][2]);
    }
    for (size_t i = 0; i < seeds_sz; i++) {
        for (size_t r = 0; r < map_row; r++) {
            if (seeds[i] >= map[r][1] && seeds[i] < (map[r][1] + map[r][2])) {
                seeds[i] += (map[r][0] - map[r][1]);
                break;
            }
        }
    }
}

int
main(int argc, char** argv)
{
    AOCInput inp;
    Stage s = START;
    long map[100][3];
    long seeds[20];
    long answer = 0;

    char *filename, *t;

    size_t  width = 0, seeds_sz = 0, map_col = 0, map_row = 0;

    filename = argc == 2 ? argv[1] : "sample.txt";
    inp = read_file_to_string(filename);

    while (inp.data[width] != '\n') {
        width++;
    }
    width++;
    printf("Width: %zu\n", width);

    for (t = strtok(inp.data, " \n"); t; t = strtok(NULL, " \n")) {
        if (set_stage(&s, t)) {
            printf("stage: '%d'\n", s);
            if (map_row) {
                calculate_dest(map, map_row, seeds, seeds_sz);
                for (size_t i = 0; i < seeds_sz; i++) {
                    printf("location: %ld ", seeds[i]);
                }
                printf("\n");
                map_col = map_row = 0;
            }
        } else {
            switch (s) {
                case SEEDS:
                    seeds[seeds_sz++] = atol(t);
                    break;
                case SEED_TO_SOIL:
                case SOIL_TO_FERTILIZER:
                case FERTILIZER_TO_WATER:
                case WATER_TO_LIGHT:
                case LIGHT_TO_TEMPERATURE:
                case TEMPERATURE_TO_HUMIDITY:
                case HUMIDITY_TO_LOCATION:
                    fill_map(map, &map_row, &map_col, t);
                    break;
                default: {
                    fprintf(stderr, "ERROR: Unknown stage");
                }
            }
        }
    }
    calculate_dest(map, map_row, seeds, seeds_sz);
    for (size_t i = 0; i < seeds_sz; i++) {
        printf("location: %ld\n", seeds[i]);
        if (answer == 0)
            answer = seeds[i];
        answer = answer < seeds[i] ? answer : seeds[i];
    }
    printf("\n");

    printf("Answer: %zu\n", answer);
    return 0;
}
