// A program to remove trailing blanks, tabs from each line of input, and to delete
// entirely blank lines.

#include <stdio.h>
#define MAX_LINE 1000

int cgetline(char s[], int lim);
int remove_character(char s[], int len);

int main(int argc, char** argv) {
    char s[MAX_LINE];
    int len;

    while ((len = cgetline(s, MAX_LINE)) > 0) {
        printf("l: \%d - \%s", len, s);
        int rlen = remove_character(s, len);
        if (rlen > 1) {
            printf("l: \%d - \%s",rlen, s);
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

int remove_character(char s[], int len) {
    int i = len - 2; // Ignore the last two characters \n and \0

    while (s[i] == ' ' || s[i] == '\t') {
        --i;
    }
    s[++i] = '\n';
    s[++i] = '\0';
    
    return i; // don't count the \0
}
