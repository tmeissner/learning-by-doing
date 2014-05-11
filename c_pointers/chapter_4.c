#include <stdlib.h>
#include <stdio.h>


void displayArray(int arr[], size_t size);
void displayArrayPtr(int *arr, size_t size);
int safeCompare(const void *a, const void *b, size_t asize, size_t bsize);
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


int safeCompare(const void *a, const void *b, size_t asize, size_t bsize) {
    if (asize != bsize) {
        return -1;
    }
    int value = 0;
    for (size_t i = 0; i < asize; i++) {
        //value |= a[i] ^ b[i];
        value |=  ((char*) a)[i] ^ ((char*) b)[i];
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
        // declare a 2-dimensional array
        int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
        for (size_t i = 0; i < 2; i++) {
            for (size_t j = 0; j < 5; j++) {
                printf("matrix[%zu][%zu] Address: %p Value %d\n", i, j, &matrix[i][j], matrix[i][j]);
            }
        }
        // declare a pointer to a 2-dimensional array
        int (*pmatrix)[5] = matrix;

        // 1st row
        printf("%p\n", matrix);
        // 2nd row
        printf("%p\n", matrix + 1);
        // size of 1st row
        printf("sizeof(matrix[0]): %zu\n", sizeof(matrix[0]));
        // access 2nd element
        printf("%p %d\n", matrix[0] + 1, *(matrix[0] + 1));
    }

    // test safeCompare function
    {
        // test with char parameters
        char a[] = "wurst";
        char b[] = "wurst";
    
        if(safeCompare(a, b, sizeof(a), sizeof(b))) {
            printf("%s ungleich %s\n", a, b);
        } else {
            printf("%s gleich %s\n", a, b);
        }
    
        // test with int parameters
        int bla[] = {0,1,2,3,4};
        int bli[] = {0,1,2,3,4};
    
        if(safeCompare(bla, bli, sizeof(bla), sizeof(bli))) {
            printf("%s ungleich %s\n", "bla", "bli");
        } else {
            printf("%s gleich %s\n", "bla", "bli");
        }
    }

    return 0;

}