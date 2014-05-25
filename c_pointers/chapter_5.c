#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {

    // print size of char & character literal
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof('a'));


    // when a string is not a constant
    // doesn't work with gcc anymore, also with -Wno-deprecated-writable-strings
    // gives 'Bus error: 10'
    {
        char *tabHeader = "Sound";
        //*tabHeader = 'L';
        printf("%s\n", tabHeader);
    }


    // string initialization
    {
        // array of char
        char header[] = "Media Player";
        printf("%s\n", header);

        header[0] = 'W';
        header[1] = 'u';
        header[2] = 'r';
        header[3] = 's';
        header[4] = 't';
        header[5] = '\0';
        printf("%s\n", header);

        // pointer to char (with memory allocation)
        char *headerPtr = malloc(strlen("Media Player") + 1);
        strcpy(headerPtr, "Media Player");
        printf("%s\n", headerPtr);

        *headerPtr       = 'W';
        *(headerPtr + 1) = 'u';
        *(headerPtr + 2) = 'r';
        *(headerPtr + 3) = 's';
        *(headerPtr + 4) = 't';
        *(headerPtr + 5) = '\0';
        printf("%s\n", headerPtr);
        for (size_t j = 0; j < strlen(headerPtr); j++) {
            printf("headerPtr[%zu] Address: %p  Value: %c\n", j, &headerPtr[j], headerPtr[j]);
        }
        printf("\n");

    }

    return 0;

}