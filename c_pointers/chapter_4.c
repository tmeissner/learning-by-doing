#include <stdlib.h>
#include <stdio.h>


int main(void) {

    int vector[5] = {1,2,3,4,5};
    int *pv = vector;

    printf("length of vector: %zu\n", sizeof(vector)/sizeof(int));

    int matrix[2][3] = {{1,2,3},{4,5,6}};

    for (size_t index = 0; index < 2; index++) {
        printf("&matrix[%zu]: %p  sizeof(matrix[%zu]): %zu\n",
            index, &matrix[index], index, sizeof(matrix[index]));
    }

    int value = 3;
    for(size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
        *pv++ *= value;
        //pv[index] *= value;
        //*(pv + index) *= value;
        //vector[index] *= value;
    }

    for(size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
        printf("vector[%zu]: %d\n", index, vector[index]);
    }

    return 0;

}