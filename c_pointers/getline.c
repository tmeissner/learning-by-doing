#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *getLine(void);
char *trim(char *phrase);


char *getLine(void) {

    const size_t sizeIncrement = 10;
    char *buffer = malloc(sizeIncrement);
    char *currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;

    if (currentPosition == NULL) {
        return NULL;
    }

    while (1) {
        character =fgetc(stdin);
        if (character == '\n') {
            break;
        }
        if (++length >= maximumLength) {
            char *newBuffer = (char*) realloc(buffer, maximumLength += sizeIncrement);
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}


char *trim(char *phrase) {

    char *old = phrase;
    char *new = phrase;

    while (*old == ' ') {
        old++;
    }

    while (*old) {
        *new = *old;
        new++;
        old++;
    }

    *new = 0;
    return (char*) realloc(phrase, strlen(phrase) + 1);
}


int main(void) {


    char *buffer = trim(getLine());

    if (buffer == NULL) {
        printf("%s\n", "out of memory");
    } else {
        printf("%s\n", buffer);
        free(buffer);
    }

    return 0;

}