#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// summary ofstring placement
/*
char *globalHeader = "Chapter";
char globalArrayHeader[] = "Chapter";

void displayHeader() {
    static char *staticHeader = "Chapter";
    char *localHeader = "Chapter";
    static char staticArrayHeader[] = "Chapter";
    char localArrayHeader[] = "Chapter";
    char *heapHeader = malloc(strlen("Chapter")+1);
    strcpy(heapHeader, "Chapter");
}
*/


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

        // direct init with character pointer
        // don't create a new copy, instead a reference to string literal pool only
        char *headerRef = "Media Player";
        printf("%s\n", headerRef);

        // you shouldn't assign a char pointer with a character literal
        // because character literals is of type int
        // wrong:
        // char *prefix = '+';
        // better:
        char *prefix = malloc(2);
        *prefix = '+';
        *(prefix + 1) = 0;
        printf("%s\n", prefix);
        free(prefix);

        // string initialisation from standard in
        // don't forget to allocate memory before read from standard in
        // wrong:
        // char *command;
        // printf("%s: ", "Enter a command");
        // scanf("%s", command);
        // better:
        char *command = malloc(11);
        printf("%s: ", "Enter a command");
        scanf("%10s", command);
        printf("You entered: %s with length: %zu\n", command, strlen(command));
        free(command);

        // memset buffer overflow test
        // executes without warnings or errors on osx :D
        char *mem = malloc(11);
        memset(mem, 0x42, 64);
        free(mem);

    }

    // standard string operations

    // comparing strings
    {
        char command[16];
        printf("Enter a command: ");
        scanf("%15s", command);
        // return value of strlen == 0 -> strings are equal
        if (!strcmp(command, "quit")) {
            printf("The command was quit\n");
        } else {
            printf("The command wasn't quit\n");
        }
    }

    return 0;

}