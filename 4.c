#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128
// #define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);
    fgets(str, STRING_SIZE, stdin);
    int * counts = (int *)malloc(sizeof(int) * ALPHABET_SIZE);

    for (int i = 0; i < ALPHABET_SIZE; i++)
        counts[i] = 0;

    for (int i = 0; i < STRING_SIZE; i++) {
        char current = tolower(str[i]);
        if (current != NULL)
            counts[(int)current] = counts[(int)current] + 1;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] == 3) {
            printf("%c", (char)i);
            break;
        }
    }

    free(str);
    free(counts);
    return 0;
}