#include <stdio.h>

int bitXor(int x, int y) {
    return ~(~x & ~y) & ~(x & y);
}

int main() {
    int x = 4;
    int y = 5;

    int result = bitXor(x, y);

    return 0;
}