//
// Created by Jakub Josef Forman on 17.09.2024.
//

#include <ctype.h>
#include "caesar.h"


void encrypt(char text[], int shift) {
    char ch;
    int i = 0;

    while (text[i] != '\0') {
        ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            // if (ch >= 65 && ch <= 90) {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }

        if (islower(ch)) {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        text[i] = ch;
        i++;
    }
}
void decrypt(char text[], int shift) {
    char ch;
    int i = 0;

    while (text[i] != '\0') {
        ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            // if (ch >= 65 && ch <= 90) {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }

        if (islower(ch)) {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        text[i] = ch;
        i++;
    }
}