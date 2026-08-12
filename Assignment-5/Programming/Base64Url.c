#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char BASE64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
char* encode(const char* input) {
    int len = strlen(input);
    int outputLen = 4 * ((len + 2) / 3);
    char* output = malloc(outputLen + 1);
    int j = 0;
    for (int i = 0; i < len; i += 3) {
        int b1 = input[i];
        int b2 = (i + 1 < len) ? input[i + 1] : 0;
        int b3 = (i + 2 < len) ? input[i + 2] : 0;
        int group1 = (b1 >> 2) & 63;
        int group2 = ((b1 & 3) << 4) | ((b2 >> 4) & 15);
        int group3 = ((b2 & 15) << 2) | ((b3 >> 6) & 3);
        int group4 = b3 & 63;
        output[j++] = BASE64[group1];
        output[j++] = BASE64[group2];
        if (i + 1 < len) output[j++] = BASE64[group3];
        else output[j++] = '=';

        if (i + 2 < len)
            output[j++] = BASE64[group4];
        else
            output[j++] = '=';
    }

    output[j] = '\0';

    return output;
}


int main() {

    const char* text = "";

    char* encoded = encode(text);

    printf("Original : %s\n", text);
    printf("Encoded  : %s\n", encoded);
    free(encoded);
   

    return 0;
}