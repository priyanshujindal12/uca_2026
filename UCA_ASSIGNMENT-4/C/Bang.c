#include <stdio.h>

int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}

int main() {
    int x = 0;

    int result = bang(x);

    return 0;
}