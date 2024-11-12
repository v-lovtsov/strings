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

    int ltwordsz = 0;
    int minsize = 128;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (ltwordsz < minsize)
                minsize = ltwordsz;

            ltwordsz = -1;
        }
        
        ltwordsz++;
    }

    printf("%d", minsize);

    free(str);
    return 0;
}