#include <cstdio>
#include <cstring>
#include <cstdlib>

char shift(char* chr, int key);

char unshift(char* chr, int key);

char* encrypt(char* rawText, int key);

char* decrypt(char* rawText, int key);

int main() {
    char myText[] = "Roses are red, violets are blue";

    char* result = encrypt(myText,1);
    printf("%s\n", result);

    char* result2 = decrypt(result, 1);
    printf("%s\n", result2);
}

char shift(char chr, int key) {
    key = key % 26;
    int shifted;

    if ((int) chr > 96 && (int) chr < 123) {
        shifted = ((int) chr + key);
        if (shifted > 122) {
            shifted = 96 + shifted % 122;
        }
        return (char) shifted;
    }

    if ((int) chr > 65 && (int) chr < 91) {
        shifted = ((int) chr + key);
        if (shifted > 90) {
            shifted = 65 + shifted % 90;
        }
        return (char) shifted;
    }

    return chr;
}

char unshift(char chr, int key) {
    key = key % 26;
    int shifted;

    if ((int) chr > 96 && (int) chr < 123) {
        shifted = ((int) chr - key);
        if (shifted < 96) {
            shifted = 122 - (96 - shifted);
        }
        return (char) shifted;
    }

    if ((int) chr > 65 && (int) chr < 91) {
        shifted = ((int) chr - key);
        if (shifted < 65) {
            shifted = 90 - (65 - shifted);
        }
        return (char) shifted;
    }

    return chr;
}

char* encrypt(char* rawText, int key) {
    char* result = (char*)calloc(strlen(rawText), sizeof(char));

    for (int i = 0; i < strlen(rawText); i++) {
        result[i] = shift(rawText[i], key);
    }

    return result;
}

char* decrypt(char* rawText, int key) {
    char* result = (char*)calloc(strlen(rawText), sizeof(char));

    for (int i = 0; i < strlen(rawText); i++) {
        result[i] = unshift(rawText[i], key);
    }

    return result;
}