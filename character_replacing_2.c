// A program to replace each tab by \t
// Each backspace by \b, and backslace by \\
//

#include <stdio.h>

int main(int argc, char** argv) {
    int c;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':
                printf("\\t");
                break;

            case '\b':
                printf("\\b");
                break;
                
            case '\\':
                printf("\\\\");
                break;

            default:
                putchar(c);
                break;
                
        }
    }
    return 0; // no error
}
