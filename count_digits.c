// A program to count digits, white space and other.
#include <stdio.h>
#define AC 10

int main(int argc, char** argv) {
    int c, ns, no;
    int ndigit[AC];
    ns = no = 0;

    int i;
    for (i = 0 ; i < AC ; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++ns;
        } else {
            ++no;
        }
    }

    for (i = 0; i < AC ; i++) {
        printf("\%d ", ndigit[i]);
    }
    printf("\b, white space = \%d, other = \%d\n", ns, no);
}
