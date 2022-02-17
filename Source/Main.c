#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enigma.h"

char* inputPlainText(FILE* inputPointer, size_t num, size_t* bufferSize);
void displayCipher(const char cipherText[]);

int main(void) {
    Enigma enigma; // instantiate the enigma machine
    char* plainText;
    char* cipherText;
    size_t bufSize = 0;
    int quit = 0;


    while (!quit) {
        eng_iniSettings(&enigma); // initialize the enigma machine and settings
                                  
        // get user input string
        plainText = inputPlainText(stdin, 200, &bufSize);
        // allocate memory for cipherText
        if (bufSize) {
            cipherText = (char*)malloc(sizeof(*cipherText) * bufSize + sizeof(*cipherText));
            if (!cipherText) {
                free(plainText);
                return -1;
            }
        }
        else {
            free(plainText);
            return -1;
        }

        // encrypt a single character
        for (int i = 0; i < bufSize; i++) {
            cipherText[i] = eng_processCharacter(&enigma, plainText[i]);
        }

        /* or encrypt the entire string
        cipherText = eng_processString(&enigma, cipherText, plainText, bufSize);
        */

        displayCipher(cipherText);

        free(plainText);
        free(cipherText);

        printf("\nEncrypt another message? Y/N: ");
        quit = fgetc(stdin);
        getchar(); // clear newline
        if (quit == 89 || quit == 121) {
            quit = 0;
        }
    }

    return 0;
}

char* inputPlainText(FILE* inputPointer, size_t num, size_t* bufferSize) {
    printf("Enter the text to encrypt: \n");
    char* str;
    int ch;
    size_t len = 0;
    str = (char*)realloc(NULL, sizeof(*str) * num);
    if (!str) {
        return str; // realloc failed
    }
    while ((ch = fgetc(inputPointer)) != EOF && ch != '\n') {
        str[len++] = ch;
        if (len == num) {
            char* tempStr = str;
            str = (char*)realloc(str, sizeof(*str) * (num += 64));
            if (!str) {
                free(tempStr);
                return str; // realloc failed
            }
        }
    }

    str[len++] = '\0'; // append null terminator
    *bufferSize = sizeof(*str) * len;
    return (char*)realloc(str, sizeof(*str) * len);
}

void displayCipher(const char cipherText[]) {
    if (!cipherText) {
        printf("Error, cipherText is NULL\n");
        return;
    }

    printf("The cipher text is:\n");
    char buf[2];
    int i = 0;
    int tab = 1;

    while (cipherText[i]) {
        snprintf(buf, 2, "%c", cipherText[i]);
        fputs(buf, stdout);
        if (!(tab % 5)) {
            snprintf(buf, 2, "\t");
            fputs(buf, stdout);
            tab = 0;
        }
        tab++;
        i++;
    }
}
