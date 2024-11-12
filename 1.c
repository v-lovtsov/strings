#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 100

int main() {
    char * str = malloc(sizeof(char) * STRING_SIZE);
    fgets(str, STRING_SIZE, stdin);

    int count = 0;
    int maxcount = 0;

    for (int i = 1; i < STRING_SIZE; i++) {
        if (str[i] == ' ')
            count++;
        else {
            maxcount = maxcount > count ? maxcount : count;
            count = 0;
        }
    }
    
    printf("%d\n", maxcount);

    free(str);
    return 0;
}