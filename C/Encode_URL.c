#include <stdio.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }
    int index = true_length + (space_count * 2);
    str[index] = '\0';

    for (int i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main() {
    char str[50] = "Hello World";
    url_encode(str, 11);
    printf("%s\n", str);
    return 0;
}