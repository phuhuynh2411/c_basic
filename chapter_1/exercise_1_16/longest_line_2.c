
// A program to print a longest line to the screen.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 10

int cgetline(char* s, int size);
void copy(char* to, char* from);

int main(int argc, char** argv) {
    int max;    // Maximum number of characters
    int len;    // The length of the current line
    char* line = malloc(MAX_LINE);
    if (!line) {
        printf("Memory allocation failed\n");
        return 1;
    }
    char* longest = malloc(MAX_LINE);
    if (!longest) {
        printf("Memory allocation failed\n");
        return 1;
    }

    max = 0;

    printf("Enter lines (press Ctr+D to end).\n");
    while ((len = cgetline(line, MAX_LINE)) > 0) {
        if (len > max) {
            max = len;
            longest = realloc(longest, len);
            if (!longest) {
                printf("Memory allocation failed\n");
                return 1;
            }
            copy(longest, line);
        }
    }
    printf("The longest line is: %s\n", longest);
    free(line);
    free(longest);
}

int cgetline(char* s, int size) {
    int c, i;
    i = 0;
    
    while ((c = getchar()) != EOF && c != '\n') {
        if (i == size - 1) {
            int old_size = size;
            size = size * 2;
            char* newline = malloc(size);
            if (!newline) {
                printf("Memory allocation failed\n");
                return 0;
            }
            // memcpy(newline, s, 10 * sizeof(int));
            for (int j = 0; j < old_size; j++) {
                newline[j] = s[j];
            }

            *s = *newline;
            free(newline);
        }
        s[i] = c;
        i++;

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

void copy(char* to, char* from) {
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
