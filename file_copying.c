#include <stdio.h>

int main(int argc, char** argv){
    int c;
    printf("End of file: %d\n", EOF);
    while((c = getchar()) != EOF){
        putchar(c);
    }
    return 0;
}
