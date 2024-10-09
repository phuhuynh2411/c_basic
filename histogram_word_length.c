// A program to display a histogram of the length of words by given text or a dataset.

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define IN 1
#define OUT 0

int main() {
    int word_length[MAX_WORD_LENGTH + 1];
    int state, c, length;

    for (int i = 0; i <= MAX_WORD_LENGTH; i++)
        word_length[i] = 0;

    state = OUT;
    length = 0;
    printf("Enter word (press Ctr+D or Ctr+Z to end).\n");

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            if (state == IN) {
                // We just finished a word
                ++word_length[length];
                length = 0;
            }
            state = OUT;
        } else {
            // Inside a word
            state = IN;
            ++length;
        }
    }

    printf("Histogram of the word length\n");
    printf("Horizontal bars:\n");

    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (word_length[i] > 0) {
            printf("\%d: ", i);
            for (int j = 0; j < word_length[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    printf("\nVertical bars:\n");
    // Find the maximum number of word length.
    int max_length = 0;
    int last_index = 0; // Last index of the array that has word length that is greater than 0.

    for (int i = 0; i <= MAX_WORD_LENGTH; i++) {
        if (max_length < word_length[i])
            max_length = word_length[i];

        if (word_length[i] > 0)
            last_index = i;
    }

    for (int i = max_length; i >= 1; i--) {
        for (int j = 1; j <= last_index; j++) {
            if (word_length[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    // Print the index
    for (int i = 1; i <= last_index; i++)
        printf("\%2d ", i);

    printf("\n");
    return 0;
}
