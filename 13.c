#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_SIZE 100
#define ALPHABET_SIZE 128

int check_ticket(char * ticket) {
    int len = strlen(ticket);

    if (len % 2 != 0)
        return 0;

    int s1 = 0;
    int s2 = 0;

    for (int i = 0; i < len / 2; i++)
        s1 += (int)ticket[i] - '0';
    for (int i = len / 2; i < len; i++)
        s2 += (int)ticket[i] - '0';

    return s1 == s2;
}

int main() {
    char * str = (char *)malloc(sizeof(char) * STRING_SIZE);

    int count = 0;
    
    do {
        count++;
        fgets(str, STRING_SIZE, stdin);

        int len = strlen(str);
        str[len - 1] = '\0';
    } while(!check_ticket(str));

    printf("%d", count);
    

    printf("\n");

    free(str);
    return 0;
}