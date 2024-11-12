#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128
// #define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int compare(char * w1, char * w2) {
    // int lenw1 = strlen(w1);
    int lenw2 = strlen(w2);
    if (w1 == NULL || w2 == NULL)
        return 0;

    return strcmp(w1, w2) == 0 ? 1 : 0;
}

int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);
    
    fgets(str, STRING_SIZE, stdin);

    int len = strlen(str);
    str[len - 1] = '\0';

    char * first = strtok(str, " ");

    char * next = strtok(NULL, " ");

    while (next != NULL) {
        int nextlen = strlen(next);

        int is_correct = 1;
        
        for (int i = 0; i < nextlen; i++) {
            for (int j = i + 1; j < nextlen; j++) {
                if (next[i] == next[j]) {
                    is_correct = 0;
                    break;
                }
            }
            if (!is_correct)
                break;
        }

        if (!compare(first, next) && is_correct) {
            puts(next);
        }

        next = strtok(NULL, " ");
    }


    printf("\n");

    free(str);
    return 0;
}