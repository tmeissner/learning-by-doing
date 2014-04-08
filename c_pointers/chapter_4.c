#include <stdlib.h>
#include <stdio.h>


int main(void) {

    int vector[5] = {1,2,3,4,5};
    int *pv;

    pv = vector;

    printf("length of vector: %zu\n", sizeof(vector)/sizeof(int));

    int matrix[2][3] = {{1,2,3},{4,5,6}};

    for (size_t index = 0; index < 2; index++) {
        printf("&matrix[%zu]: %p  sizeof(matrix[%zu]): %zu\n",
            index, &matrix[index], index, sizeof(matrix[index]));
    }

    // pointer notation and arrays
    int value = 3;
    for(size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
        // all following operations are equivalent
        *pv++ *= value;
        //pv[index] *= value;
        //*(pv + index) *= value;
        //vector[index] *= value;
    }
    for(size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
        printf("vector[%zu]: %d\n", index, vector[index]);
    }

    // using malloc to create a one-dimensional array
    pv = (int*) malloc(5 * sizeof(int));
    for (size_t i = 0; i < 5; i++)
    {
        pv[i] = i + 1;
    }
    for (size_t i = 0; i < 5; ++i)
    {
        *(pv + i) = i + 1;
    }
    for(size_t index = 0; index < 5; index++) {
        printf("pv[%zu]: %d\n", index, pv[index]);
    }

    return 0;

}