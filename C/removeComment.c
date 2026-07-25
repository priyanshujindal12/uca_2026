#include <stdio.h>
int main() {
    int c, next;
    int in_string = 0, in_char = 0;
    while ((c = getchar()) != EOF) {
        if (in_string) {
            putchar(c);
            if (c == '\\') {          // Escape sequence
                if ((next = getchar()) != EOF)
                    putchar(next);
            } else if (c == '"') {
                in_string = 0;
            }
        }
        else if (in_char) {
            putchar(c);

            if (c == '\\') {
                if ((next = getchar()) != EOF)
                    putchar(next);
            } else if (c == '\'') {
                in_char = 0;
            }
        }
        else if (c == '"') {
            in_string = 1;
            putchar(c);
        }
        else if (c == '\'') {
            in_char = 1;
            putchar(c);
        }
        else if (c == '/') {
            next = getchar();
            if (next == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            }
            else if (next == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }
            else {
                putchar(c);
                if (next != EOF)
                    putchar(next);
            }
        }
        else {
            putchar(c);
        }
    }

    return 0;
}