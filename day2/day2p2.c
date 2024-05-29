#include <stdio.h>
#include <string.h>

const char* example = "\
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";

typedef struct {
    size_t number;
    int max_blue;
    int max_green;
    int max_red;
} Game;

#define T_GAME "Game"
#define T_R    "red"
#define T_G    "green"
#define T_B    "blue"
#define SPACE ' '
#define EOL '\0'


int main() {
    //int sum = 0;
    //Game games[1024];
    //size_t game_number = 0;
    size_t token_length = 0;
    char token[10];
    printf("Example: %s", example);

    for (int i = 0; i < strlen(example); i++) {
        char cur = example[i];

        if (cur != SPACE && cur != '\n'){
            token[token_length] = cur;
            token_length++;
        } else {
            token[token_length] = EOL;
            if (bcmp(token, T_GAME, 2) == 0) {
                printf("%s\n",T_GAME);
            } else if (bcmp(token, T_R, 2) == 0) {
                printf("%s\n",T_R);
            } else if (bcmp(token, T_G, 2) == 0) {
                printf("%s\n",T_G);
            } else if (bcmp(token, T_B, 2) == 0) {
                printf("%s\n",T_B);
            } else {
                printf("Token %s\n", token);
            }
            token_length = 0;
        }
    }
}
