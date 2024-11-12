#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128
#define KEYWORDS_SIZE 33
// #define ALPHABET "abcdefghijklmnopqrstuvwxyz"
 
char *keywords[KEYWORDS_SIZE] = {
    "False", "True", "None", "and",
    "with", "as", "assert", "break",
    "class", "continue", "def", "del",
    "elif", "else", "except", "finally",
    "for", "from", "global", "if", "import",
    "in", "is", "lambda", "nonlocal", "not",
    "or", "pass", "raise", "return", "try",
    "while", "yield"
};

char *nums = "1234567890";

int compare(char * w1, char * w2) {
    // int lenw1 = strlen(w1);
    int lenw2 = strlen(w2);
    if (w1 == NULL || w2 == NULL)
        return 0;

    return strcmp(w1, w2) == 0 ? 1 : 0;
}

int iskeyword(char * word) {
    for (int i = 0; i < KEYWORDS_SIZE; i++)
        if (compare(word, keywords[i]))
            return 1;

    return 0;
}

int check_symbol(char symbol) {
    int sym = (int)symbol;

    int numscond = sym >= 48 && sym <= 57;
    int uppercond = sym >= 65 && sym <= 90;
    int lowercond = sym >= 97 && sym <= 122;
    int snakecond = sym == 95;

    return numscond ||
        uppercond ||
        lowercond ||
        snakecond;
}

int check_word(char * word) {
    for (int i = 0; i < 10; i++)
        if (word[0] == nums[i])
            return 0;

    int len = strlen(word);

    for (int i = 0; i < len; i++)
        if (!check_symbol(word[i]))
            return 0;

    return 1;
}


int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);
    
    fgets(str, STRING_SIZE, stdin);

    int len = strlen(str);
    str[len - 1] = '\0';

    
    if (check_word(str))
        puts("Can be a name in python");
    else
        puts("Can not be a name in python!");

    printf("\n");

    free(str);
    return 0;
}