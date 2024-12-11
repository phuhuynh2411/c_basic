// “Write a program to “fold” long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.”

#include <stdio.h>
#define COLUMN_LIMIT 20
#define LINE_LIMIT 1000

int main(int argc, char** argv) {
    int c;
    int line_pos = 0;
    char array_character[LINE_LIMIT];

    while ((c = getchar()) != EOF) {
        // Prevent buffer overflow
        if (line_pos < LINE_LIMIT) {
            array_character[line_pos] = c;
            ++line_pos;
        }

        if (line_pos == COLUMN_LIMIT) {
            // Find the last non-blank character
            int i = line_pos - 1;
            while (i > 0 && array_character[i] != ' ') {
                --i;
            }
            // i is either at 0 or
            // i at ' ' 
            // i at ' \t'

            if (i == 0) {
                // No space or tab found
                // put the characters to the COLUMN LIMIT
                for(int j = 0; j < COLUMN_LIMIT; j++) {
                    putchar(array_character[j]);
                }
                line_pos = 0;
            } else {
                // Found a space or tab
                // put characters to the i
                for(int j = 0; j <= i; j++) {
                    putchar(array_character[j]);
                }
                // Put the remaning characters to the new line
                int index = 0;
                for(int j = i + 1; j < line_pos; j++) {
                    array_character[index] = array_character[j];
                    ++index;
                }
                line_pos = index;
            }
            putchar('\n');

        } else if (c == '\n') {
            for(int i = 0; i < line_pos; i++) {
                putchar(array_character[i]);
            }            
            line_pos = 0;
        }
        
    }

   // Print any remaining buffered characters if not followed by a newline
    for(int i = 0; i < line_pos; i++) {
        putchar(array_character[i]);
    } 

    return 0;
}
