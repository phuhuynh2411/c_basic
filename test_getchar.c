#include <stdio.h>

int main() {
    int c, len;
    len = 0;

    while (c != EOF) {
        ++len;
        c = getchar();
        putchar(c);
    }
    printf("Length = \%d", len);

    return 0;
}
