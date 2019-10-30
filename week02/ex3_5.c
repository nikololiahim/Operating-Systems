// ex3 <number> <argument>
// <number> - any number greater than 0
// <argument> - either "-h", "-a", "-s" or no argument
// no argument - prints an equilateral triangle with side <number>
// -h - prints the right half of an equilateral triangle with side <number>
// -a - prints the "arrow"-type figure
// -s - prints a square <number> x <number>

#include <stdio.h>
#include <string.h>


int to_int(char* s) {
    int num = 0;
    int negate = 1;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] != '-') {
            num = num * 10 + s[i] - '0';
        }
        else {
            negate = -1;
        }
    }
    return num * negate;
}


int main(int argc, char** argv) {
    int n = to_int(argv[1]);
    int offset = n-1;
    int stars = 1;
    if (argv[2] == NULL) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < offset; ++j) {
                printf(" ");
            }
            for (int j = 0; j < stars; ++j) {
                printf("*");
            }
            for (int j = 0; j < offset; ++j) {
                printf(" ");
            }
            printf("\n");
            --offset;
            stars += 2;
        }
    }
    else if (strcmp(argv[2], "-h") == 0) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 0; j < i; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (strcmp(argv[2], "-a") == 0) {
        for (int i = 1; i < n/2+1; ++i) {
            for (int j = 0; j < i; ++j) {
                printf("*");
            }
            printf("\n");
        }
        for (int i = n/2 + n%2; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (strcmp(argv[2], "-s") == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }
    else {
        printf("Unknown argument! Try \"-h\", \"-a\", or \"-s\".\n");
    }
}