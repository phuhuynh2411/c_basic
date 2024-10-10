// A program to print a histogram of the frequeceies of different characters in its input
#include <stdio.h>

int main() {
    int freq[128] = {0}; // Init all array elements to zero
    int c;
    printf("Enter characters (press Ctr+D to end.)\n");

    while ((c = getchar()) != EOF) {
        ++freq[c];
    }

    // Print a history gram
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            printf("\%c: ", i);
            for (int j = 0; j < freq[i]; j++) {
                printf("*");
            }  
            printf("\n");
        }
    }
}
