#include <stdio.h>

int main(int argn, char** argv){
    long nc;
    nc = 0;

    while(getchar() != EOF){
        ++nc;
    }
    printf("Character count: \%ld\n", nc);
}
