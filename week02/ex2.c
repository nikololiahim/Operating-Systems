#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_CAPACITY 16
#define GROWTH_FACTOR 2

char* readline(FILE* fp) {

    int capacity = INITIAL_CAPACITY;
    int size = 0;
    int c;
    char* res = (char*) malloc(sizeof(char)*capacity);

    while ( (c = fgetc(fp)) != EOF && c != '\n') {
        if (size + 1 == capacity) {
            res = (char *) realloc(res, capacity * GROWTH_FACTOR);
        }
        res[size++] = c;
    }
    res[size] = '\0';

    return res;
}

char* reverse(char* s) {
    int length = strlen(s);
    char* res = (char*) malloc(sizeof(char) * length + 1);
    for (int i = length-1; i > -1; --i) {
        res[length - i - 1] = s[i];
    }
    res[length] = '\0';
    return res;
}

int main() {


    printf("Please, enter a string:\n");
    char* s = readline(stdin);
    char* rev = reverse(s);

    printf("Here is the reverse of this string:\n%s", rev);

    free(rev);
    free(s);
    return 0;
}