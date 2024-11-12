#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128
// #define ALPHABET "abcdefghijklmnopqrstuvwxyz"

void fill(int * arr, int size, int val) {
    for (int i = 0; i < size; i++)
        arr[i] = val;
}

int main() {
    char * str1 = (char *)malloc(sizeof(char) * STRING_SIZE);
    char * str2 = (char *)malloc(sizeof(char) * STRING_SIZE);
    char * str3 = (char *)malloc(sizeof(char) * STRING_SIZE);

    fgets(str1, STRING_SIZE, stdin);
    fgets(str2, STRING_SIZE, stdin);
    fgets(str3, STRING_SIZE, stdin);

    int * counts1 = (int *)malloc(sizeof(int) * ALPHABET_SIZE);
    int * counts2 = (int *)malloc(sizeof(int) * ALPHABET_SIZE);
    int * counts3 = (int *)malloc(sizeof(int) * ALPHABET_SIZE);

    fill(counts1, ALPHABET_SIZE, 0);
    fill(counts2, ALPHABET_SIZE, 0);
    fill(counts3, ALPHABET_SIZE, 0);

    for (int i = 0; i < STRING_SIZE; i++) {
        char current1 = tolower(str1[i]);
        char current2 = tolower(str2[i]);
        char current3 = tolower(str3[i]);
        if (current1 != NULL)
            counts1[(int)current1] = counts1[(int)current1] + 1;
        if (current2 != NULL)
            counts2[(int)current2] = counts2[(int)current2] + 1;
        if (current3 != NULL)
            counts3[(int)current3] = counts3[(int)current3] + 1;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts1[i] + counts2[i] + counts3[i] == 0)
            continue;

        if (counts1[i] + counts2[i] + counts3[i] == counts1[i])
            printf("%c", (char)i);
        else if (counts1[i] + counts2[i] + counts3[i] == counts2[i])
            printf("%c", (char)i);
        else if (counts1[i] + counts2[i] + counts3[i] == counts3[i])
            printf("%c", (char)i);
    }

    free(str1);
    free(str2);
    free(str3);
    free(counts1);
    free(counts2);
    free(counts3);
    return 0;
}