#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char BASE64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

int getValue(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    if (c >= '0' && c <= '9')
        return c - '0' + 52;
    if (c == '+')
        return 62;
    if (c == '/')
        return 63;
    return -1;
}



char* encode(const char* input) {
    int len = strlen(input);

    int outputLen = 4 * ((len + 2) / 3);

    char* output = malloc(outputLen + 1);

    int j = 0;

    for (int i = 0; i < len; i += 3) {

        int b1 = input[i];

        int b2 = (i + 1 < len) ? input[i + 1] : 0;
        int b3 = (i + 2 < len) ? input[i + 2] : 0;

        // Extract four 6-bit groups

        int group1 = (b1 >> 2) & 63;

        int group2 = ((b1 & 3) << 4) |
                     ((b2 >> 4) & 15);

        int group3 = ((b2 & 15) << 2) |
                     ((b3 >> 6) & 3);

        int group4 = b3 & 63;

        output[j++] = BASE64[group1];
        output[j++] = BASE64[group2];
        if (i + 1 < len)
            output[j++] = BASE64[group3];
        else
            output[j++] = '=';

        if (i + 2 < len)
            output[j++] = BASE64[group4];
        else
            output[j++] = '=';
    }

    output[j] = '\0';

    return output;
}


char* decode(const char* input) {

    int len = strlen(input);

    int outputLen = (len / 4) * 3;
    if (len > 0 && input[len - 1] == '=')
        outputLen--;

    if (len > 1 && input[len - 2] == '=')
        outputLen--;

    char* output = malloc(outputLen + 1);

    int j = 0;

    for (int i = 0; i < len; i += 4) {

        int v1 = getValue(input[i]);
        int v2 = getValue(input[i + 1]);

        int v3 = (input[i + 2] == '=') ?
                 0 : getValue(input[i + 2]);

        int v4 = (input[i + 3] == '=') ?
                 0 : getValue(input[i + 3]);


        int b1 = (v1 << 2) | (v2 >> 4);

        int b2 = ((v2 & 15) << 4) |
                 (v3 >> 2);

        int b3 = ((v3 & 3) << 6) |
                 v4;

        output[j++] = b1;

        if (input[i + 2] != '=')
            output[j++] = b2;

        if (input[i + 3] != '=')
            output[j++] = b3;
    }

    output[j] = '\0';

    return output;
}


int main() {

    const char* text = "Hello World";

    char* encoded = encode(text);

    printf("Original : %s\n", text);
    printf("Encoded  : %s\n", encoded);

    char* decoded = decode(encoded);

    printf("Decoded  : %s\n", decoded);

    free(encoded);
    free(decoded);

    return 0;
}