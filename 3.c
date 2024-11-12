#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int main() {
    char * str = malloc(sizeof(char) * STRING_SIZE);
    fgets(str, STRING_SIZE, stdin);
    char * already = malloc(sizeof(char) * strlen(ALPHABET));

    int count = 0;

    for (int i = 0; i < STRING_SIZE; i++) {
        char current = tolower(str[i]);
        if (strchr(ALPHABET, current) != NULL && strchr(already, current) == NULL) {

            already[count] = current;
            count++;
        }
    }

    printf("%d", count);

    free(str);
    free(already);
    return 0;
}