#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 100

int main() {
    char * str = malloc(sizeof(char) * STRING_SIZE);
    fgets(str, STRING_SIZE, stdin);

    int count = 0;
    int maxcount = 0;
    char current = str[0];

    for (int i = 0; i < STRING_SIZE; i++)
        if (str[i] == current)
            count++;
        else {
            maxcount = maxcount > count ? maxcount : count;
            count = 1;
            current = str[i];
        }
    
    printf("%d\n", maxcount);

    free(str);
    return 0;
}