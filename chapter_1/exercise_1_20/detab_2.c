
// A program to replace tabs in the input with proper number of blanks to space
// the next tab stop
#include <stdio.h>

#define TAB_STOP 4 // A number of blanks for each tab

int main(int argc, char** argv) {
    int n = TAB_STOP;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int space_count = n;
            for (int i = 0; i < space_count; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}
