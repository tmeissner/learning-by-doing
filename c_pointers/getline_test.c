#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "getline.h"

 
#define STRING_LENGTH 14



int tests_run = 0;


// unit test function for trim()
static char *test_trim() {

    char *foo = malloc(STRING_LENGTH + 1 * sizeof(*foo));
    int wurst = snprintf(foo, STRING_LENGTH + 1, "%s", "    hallo welt");
    
    assertf(wurst <= STRING_LENGTH, "buffer overflow");

    mu_assert("error", !(strcmp(trim(foo), "hallo welt")));
    
    return 0;

}


// function to run all tests
static char *all_tests() {

    mu_run_test(test_trim);

    return 0;

}


int main(void) {

    char *result = all_tests();
    
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}