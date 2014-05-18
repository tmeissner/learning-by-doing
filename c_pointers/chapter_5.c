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
        *tabHeader = 'L';
        printf("%s\n", tabHeader);
    }


    return 0;

}