// A program to count blanks, newlines and words
//
#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char** argv) {
    long nl, nc, nw;
    int c, state;

    nl = nc = nw = 0;
    state = OUT;

    while((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("Newlines: \%ld, characters: \%ld, words: \%ld\n", nl, nc, nw);
}
