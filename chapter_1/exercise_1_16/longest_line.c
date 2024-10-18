// A program to print a longest line to the screen.
#include <stdio.h>
#define MAX_LINE 10

int cgetline(char s[], int lim);
void copy(char to[], char from[]);

int main(int argc, char** argv) {
    int max;    // Maximum number of characters
    int len;    // The length of the current line
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;

    while ((len = cgetline(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    printf("%s", longest);
}

int cgetline(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    } 
    // The loop exists c is the break line character.
    // This break line character has not been added to the line yet.
    // This step is used to add the break line character to the line.
    if (c == '\n') {
        s[i] = '\n';
        i++;
    }

    // Add the null terminator character to the end of the line.
    // This character is used as an indicator for the end of array.
    s[i] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
