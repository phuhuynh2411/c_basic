// A program to replace each string with one or more blanks by a single blank.
//
#include <stdio.h>

int main(int argc, char** argv) {
    int c, preC;

    while ((c = getchar()) != EOF) {
        if ( !(c == preC && c == ' ') ) {
            putchar(c);
            preC = c;
        }
    }
    return 0; // no error
}
