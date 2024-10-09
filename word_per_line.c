// A program that prints its input one word per line

#include <stdio.h>

int main(int argn, char** argv) {
    int c, pc;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (pc != '\n')
                putchar('\n');

            pc = '\n';
        } else {
            putchar(c);
            pc = c;
        }
    }
}
