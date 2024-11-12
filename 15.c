#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 5
#define ALPHABET_SIZE 128

int clr() {
    for (int i = 0; i < 25; i++) {
        puts("   ");
    }
}

void fill(int * arr, int size, int val) {
    for (int i = 0; i < size; i++)
        arr[i] = val;
}

int check_cows(char * num_p, char * num_r) {
    int cows = 0;
    for (int i = 0; i < STRING_SIZE; i++) {
        for (int j = 0; j < STRING_SIZE; j++) {
            if (num_p[i] == num_r[j] && i != j)
                cows++;
        }
    }
    return cows;
}

int check_bulls(char * num_p, char * num_r) {
    int bulls = 0;
    for (int i = 0; i < STRING_SIZE; i++) {
        if (num_p[i] == num_r[i] && num_p[i] != '\0') {
            bulls++;
        }
    }    
    
    return bulls;
}

int main() {
    char * num = (char *)malloc(sizeof(char) * STRING_SIZE);

    printf("Type a num to guess: ");
    fgets(num, STRING_SIZE, stdin);

    clr();

    int rounds = 0;
    
    while (rounds < 10) {
        printf("\n");
        rounds++;
        printf("Round: %d\n", rounds);

        char * w = (char *)malloc(sizeof(char) * STRING_SIZE);
        printf("Guess the num: ");
        fflush(stdin);
        fgets(w, STRING_SIZE, stdin);

        int cows = check_cows(w, num);
        int bulls = check_bulls(w, num);

        printf("Bulls: %d Cows: %d", bulls, cows);

        if (bulls == 4) {
            printf("\nWin!\n");
            break;
        }
        free(w);
    }
    
    if (rounds > 10) {
        printf("\nYou lose(");
    }

    printf("\n");

    free(num);
    return 0;
}