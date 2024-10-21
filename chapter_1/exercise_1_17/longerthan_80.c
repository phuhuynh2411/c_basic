// A program to print all input lines that are longer than 80 characters.
#include <stdio.h>
#define MAX_LINE 1000

int cgetline(char s[], int lim);

int main(int argc, char** argv) {
    int len;
    char s[MAX_LINE];

    while ((len = cgetline(s, MAX_LINE)) > 0) {
        if (len > 80) {
            printf("%s\n", s);
        }
    }
}

int cgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';

    return i;
}
