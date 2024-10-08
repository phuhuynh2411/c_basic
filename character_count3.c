// A program that counts blanks, tabs and newlines
#include <stdio.h>

int main(int argc, char**argv){
    long bc, tc, nc;
    bc = 0;
    tc = 0;
    nc = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++bc;

        if (c == '\t') 
            ++tc;

        if (c == '\n')
            ++nc;
       
    }
    printf("Blanks: \%ld, tabs: \%ld, newlines: \%ld", bc, tc, nc);
}
