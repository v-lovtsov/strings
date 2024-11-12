#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128

int compare(char * w1, char * w2) {
    // int lenw1 = strlen(w1);
    int lenw2 = strlen(w2);
    if (w1 == NULL || w2 == NULL)
        return 0;

    return strcmp(w1, w2) == 0 ? 1 : 0;
}

int clr() {
    for (int i = 0; i < 25; i++) {
        puts("   ");
    }
}

void fill(int * arr, int size, int val) {
    for (int i = 0; i < size; i++)
        arr[i] = val;
}

int check(int * arr, int size) {
    for (int i = 0; i < size; i++)
        if (arr[i] == 0)
            return 0;
    
    return 1;
}

void push_letter(int * arr, int size, char * winword, char l) {
    for (int i = 0; i < size; i++)
        if (winword[i] == l)
            arr[i] = 1;
}

int push_word(int * arr, int size, char * winword, char * word) {
    int r = compare(winword, word);

    if (r)
        for (int i = 0; i < size; i++)
            arr[i] = 1;
}

void draw_word(int * arr, int size, char * winword) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i] == 0 ? '*' : winword[i]);
    }
    printf("\n");
}

int main() {
    char * word = (char *)malloc(sizeof(char) * STRING_SIZE);
    char * help = (char *)malloc(sizeof(char) * STRING_SIZE);

    printf("Type a word to guess: ");
    fgets(word, STRING_SIZE, stdin);

    printf("Type a help: ");
    fgets(help, STRING_SIZE, stdin);

    clr();

    int wordsz = strlen(word);
    word[wordsz - 1] = '\0';
    wordsz--;

    int * opened = (int *)malloc(sizeof(int) * wordsz);
    fill(opened, wordsz, 0);

    int rounds = 0;
    
    do {
        rounds++;
        clr();
        printf("Round: %d\n", rounds);
        printf("Tip: ");
        puts(help);
        draw_word(opened, wordsz, word);

        int type;
        printf("1 - Letter\n2 - Word\n");
        scanf("%d", &type);

        if (type == 1) {
            char l;
            printf("Type a letter: ");
            scanf(" %c", &l);
            push_letter(opened, wordsz, word, l);
        } else {
            char * w = (char *)malloc(sizeof(char) * STRING_SIZE);
            printf("Guess the word: ");
            fflush(stdin);
            fgets(w, STRING_SIZE, stdin);
            w[strlen(w) - 1] = '\0';
            push_word(opened, wordsz, word, w);
            free(w);
        }
    } while (!check(opened, wordsz) && rounds < 20);
    
    if (rounds < 20) {
        draw_word(opened, wordsz, word);
        printf("WIN!");
    } else {
        printf("\nYou lose(");
    }

    printf("\n");

    free(word);
    free(help);
    return 0;
}