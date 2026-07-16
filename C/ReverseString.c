#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;

    // Find the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string in-place
    int left = 0;
    int right = length - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char str[] = "Data Structures";

    reverse_string(str);

    printf("%s\n", str);

    return 0;
}