#include <stdio.h>

int main(int argc, char** argv){
    double nc;
    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("Character count: \%.0f\n", nc);
}
