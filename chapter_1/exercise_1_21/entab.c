// A program to replace a string of spaces with tabs
//
#include <stdio.h>
#define TAB_STOP 4

int main(int argc, char** argv) {
    int c;
    int nr_space = 0;
    int line_pos = 0;

    while ((c = getchar()) != EOF) {
        ++line_pos;

        if (c == ' ') {
            ++nr_space;
            // Do not replace 1 space with a tab 
            if (nr_space == TAB_STOP && nr_space > 1) {
                putchar('\t');
                nr_space = 0;
            }
        } else {
            // Print the number of spaces that are less than a tab stop if any.
            while (nr_space) {
                putchar(' ');
                --nr_space;
            }
            
            putchar(c);

            // Reset the line position if there is a new line
            if (c == '\n') {
                line_pos = 0;
            }
        }
    }
}
