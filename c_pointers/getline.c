#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getline.h"



int main(void) {

    // this is wrong -> realloc in trim() on array which wasn't malloc'ed
    // char blub[] = "    wurstgesicht";
    // printf("%s\n", trim(blub));

    // by using return value of getline(), we got an array which was malloc'ed
    char *buffer = trim(getLine());

    if (buffer == NULL) {
        printf("%s\n", "out of memory");
    } else {
        printf("%s\n", buffer);
        free(buffer);
    }

    return 0;

}