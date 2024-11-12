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

// void sortspaces(int * arr, int size) {
//     for (int i = 0; i < size; i++) {
//         if (arr[i] == -1)
//             continue;

//         for (int j = i; j < size; j++) {
//             if (arr[j] == -1)
//                 continue;
            
//             if (arr[i] < arr[j]) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     } 
// }

int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);
    int * spaces = (int *)malloc(sizeof(int) * STRING_SIZE);

    fgets(str, STRING_SIZE, stdin);

    fill(spaces, STRING_SIZE, -1);

    int ltwordsz = 0;

    for (int i = 0; i < STRING_SIZE; i++) {
        if (str[i] == NULL) {
            spaces[i] = ltwordsz;
            break;
        }

        if (str[i] == ' ') {
            spaces[i] = ltwordsz;
            ltwordsz = 0;
        }
        
        ltwordsz++;
    }

    for (int i = 0; i < STRING_SIZE; i++) {
        printf("%d ", spaces[i]);
    }

    sortspaces(spaces, STRING_SIZE);
    printf("\n");

    for (int i = 0; i < STRING_SIZE; i++) {
        printf("%d ", spaces[i]);
    }

    for (int i = STRING_SIZE; i >= 0; i--) {
        if (spaces[i] == -1 || spaces[i] == 0)
            continue;
        
        for (int j = i - spaces[i]; j < i; j++) {
            if (str[j] == ' ' || str[j] == '\n') continue;
            printf("%c", str[j]);
        }
        printf(" ");
    }

    free(str);
    return 0;
}