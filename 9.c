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

    char * copy = (char *)malloc(sizeof(char) * STRING_SIZE);

    int len = strlen(str);
    str[len - 1] = '\0';

    strcpy(copy, str);

    char * w1 = strtok(str, " ");
    char * w2 = strtok(NULL, " ");

    int found = 0;
    int appendi = 0;

    while (w1 != NULL) {
        while (w2 != NULL) {
            if (compare(w1, w2)) {
                found = 1;
                puts(w1);
                break;
            }
            w2 = strtok(NULL, " ");
        }

        if (found)
            break;

        appendi += strlen(w1);

        char * temp = (char *)malloc(sizeof(char) * STRING_SIZE);
        for (int i = appendi; i < strlen(copy); i++) {
            temp[i - appendi] = copy[i];
        }
        free(copy);
        copy = temp;
        str = strcpy(str, copy);
        
        w1 = strtok(str, " ");
        w2 = strtok(NULL, " ");
    }

    if (!found)
        printf("No ident words");
    

    printf("\n");

    free(str);
    return 0;
}