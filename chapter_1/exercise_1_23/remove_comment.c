// “a program to remove all comments from a C program. Don’t forget to handle quoted strings and character constants properly. C comments do not nest.”
#include <stdio.h>

typedef enum {
    NORMAL,             // Normal state
    IN_BLOCK_COMMENT,   // Inside the block comment
    IN_LINE_COMMENT,    // Inside the line comment
    IN_STRING,          // Inside the literal string for example "this is a literal string"
    IN_CHAR             // Inside the character constant for example 'k'
} State;

int main(int argn, char** argv) {
    int c;                  // The current character
    int prev_char = 0;      // The previous character
    State state = NORMAL;   // Initially, we are in the NORMAL state.
    int backslash_count = 0;

    while((c = getchar()) != EOF) {
        // Switch according to the state
        switch (state) {
            case NORMAL:
                if (c == '/') {
                    int next_char = getchar();      // Peek the next character
                    if (next_char == '*') {
                        // Start the block comment
                        state = IN_BLOCK_COMMENT;
                    } else if (next_char == '/') {
                        // Start the line comment
                        state = IN_LINE_COMMENT;
                    } else {
                        putchar(c);
                        putchar(next_char);
                    } 
                } else if (c == '\'') {
                    putchar(c);
                    // Start the character constant
                    state = IN_CHAR;
                    backslash_count = 0;

                } else if (c == '"') {
                    putchar(c);
                    // Start the String literal
                    state = IN_STRING;

                } else {
                    putchar(c);
                }
                break;

            case IN_BLOCK_COMMENT:
                if (c == '/' && prev_char == '*') {
                    // End the block comment
                    state = NORMAL;
                }
                break;

            case IN_LINE_COMMENT:
                if (c == '\n') {
                    // End the line comment
                    state = NORMAL;
                    putchar(c);         // Put the newline character to preserve the format
                }
                break;

            case IN_STRING:
                putchar(c);
                if (c == '"' && prev_char != '\\') {
                    // End the string literal
                    state = NORMAL;
                }
                break;

            case IN_CHAR:
                putchar(c);
                if (c == '\\') { 
                    backslash_count++;
                }

                if (c == '\'' && (prev_char != '\\' || backslash_count % 2 == 0)) {
                    // End the character constant
                    state = NORMAL;
                    backslash_count = 0;
                }

                break;
        }

        // Update the previous character
        prev_char = c;

    }

    return 0;
}

