#include <stdlib.h>
#include <stdio.h>


void displayArray(int arr[], size_t size);
void displayArrayPtr(int *arr, size_t size);
int safeCompare(const unsigned char *a, const unsigned char *b, size_t asize, size_t bsize);
int valid(void *p);


void displayArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        // both variants are possible
        printf("%d\n", arr[i]);
        //printf("%d\n", *(arr + i));
    }
}


void displayArrayPtr(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        // both variants are possible
        printf("%d\n", *(arr + i));
        //printf("%d\n", arr[i]);
    }
}


int safeCompare(const unsigned char *a, const unsigned char *b, size_t asize, size_t bsize) {
    if (asize != bsize) {
        return -1;
    }
    int value = 0;
    for (size_t i = 0; i < asize; i++) {
        value |= a[i] ^ b[i];
    }
    return value;
}


int main(void) {

    int vector[5] = {1,2,3,4,5};

    printf("length of vector: %zu\n", sizeof(vector)/sizeof(int));

    int matrix[2][3] = {{1,2,3},{4,5,6}};

    for (size_t index = 0; index < 2; index++) {
        printf("&matrix[%zu]: %p  sizeof(matrix[%zu]): %zu\n",
            index, &matrix[index], index, sizeof(matrix[index]));
    }

    // pointer notation and arrays
    {
        int *pv = vector;
        int value = 3;
        for (size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
            // all following operations are equivalent
            *pv++ *= value;
            //pv[index] *= value;
            //*(pv + index) *= value;
            //vector[index] *= value;
        }
        for (size_t index = 0; index < sizeof(vector)/sizeof(int); index++) {
            printf("vector[%zu]: %d\n", index, vector[index]);
        }
    }

    // using malloc to create a one-dimensional array
    {
        int *pv = malloc(5 * sizeof(*pv));
        for (size_t i = 0; i < 5; i++) {
            pv[i] = i + 1;
        }
        for (size_t i = 0; i < 5; ++i) {
            *(pv + i) = i + 1;
        }
        for(size_t index = 0; index < 5; index++) {
            printf("pv[%zu]: %d\n", index, pv[index]);
        }
    }

    // passing array to function using array notation
    displayArray(vector, sizeof(vector)/sizeof(int));

    // passing array to function using pointer notation
    displayArrayPtr(vector, sizeof(vector)/sizeof(int));


    // using a one-dimensional array of pointers
    {
        int *arr[5];
        for (size_t i = 0; i < 5; i++) {
            // both variants are equivalent
            arr[i] = malloc(sizeof(arr[i]));
            *arr[i] = i;
            //arr[i][0] = i;
            //*(arr + i) = (int*) malloc(sizeof(int));
            //**(arr + i) = i;
            printf("%d\n", **(arr + i));
        }
    }

    // pointers and multidimensional arrays
    {
        int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
        for (size_t i=0; i<2; i++) {

        }
    }

    unsigned char a[] = "wurst";
    unsigned char b[] = "wurst";

    if(safeCompare(a, b, sizeof(a), sizeof(b))) {
        printf("%s ungleich %s\n", a, b);
    } else {
        printf("%s gleich %s\n", a, b);
    }

    return 0;

}