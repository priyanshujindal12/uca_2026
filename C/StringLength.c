#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int main() {
    const char *str = "Hello, World!";

    printf("Length = %d\n", my_strlen(str));

    return 0;
}