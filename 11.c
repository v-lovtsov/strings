#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128
// #define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int compare_cities(char * w1, char * w2) {
    int len1 = strlen(w1);

    if (w1[len1 - 1] != w2[0])
        return 0;
    
    return 1;
}

int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);
    
    fgets(str, STRING_SIZE, stdin);

    int len = strlen(str);
    str[len - 1] = '\0';

    char * w1 = strtok(str, " ");

    char * w2 = strtok(NULL, " ");

    int round = 2;

    while (w1 != NULL && w2 != NULL) {
        if (round % 2 == 0) {   
            if (!compare_cities(w1, w2)) {
                puts("Petya WIN!");
                break;
            }
            w1 = strtok(NULL, " ");
        } else {
            if (!compare_cities(w2, w1)) {
                puts("Vasya WIN!");
                break;
            }
            w2 = strtok(NULL, " ");
        }

        round++;
    }

    if (w1 == NULL || w2 == NULL)
        puts(w2 == NULL ? "Petya WIN!" : "Vasya WIN!");


    printf("\n");

    free(str);
    return 0;
}