#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void displayArray(int arr[], size_t size);
void displayArrayPtr(int *arr, size_t size);
int safeCompare(const void *a, const void *b, size_t asize, size_t bsize);
int valid(void *p);
void display2DArray(int arr[][5], size_t rows);
void display2DArrayPtr(int (*arr)[5], size_t rows);
void display2DArrayUnknownSize(int *arr, size_t rows, size_t cols);
void display3DArrayPtr(int (*arr)[2][4], size_t rows);


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
        value |=  ((unsigned char*) a)[i] ^ ((unsigned char*) b)[i];
    }
    return value;
}


void display2DArray(int arr[][5], size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < 5; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}


void display2DArrayPtr(int (*arr)[5], size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < 5; j++) {
            printf("%d", *(arr[i] + j));
        }
        printf("\n");
    }
}


void display2DArrayUnknownSize(int *arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            // both are equivalent
            //printf("%d", *(arr + (i * cols) + j));
            printf("%d", (arr + (i * cols))[j]);
        }
        printf("\n");
    }
}


void display3DArrayPtr(int (*arr)[2][4], size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < 2; j++) {
            printf("{");
            for (size_t k = 0; k < 4; k++) {
                printf("%d", arr[i][j][k]);
                if (k != 3) {
                    printf(" ");
                }
            }
            printf("}");
        }
        printf("\n");
    }
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
        free(pv);
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
        for (size_t i = 0; i < 5; i++) {
            free(arr[i]);
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


    // passing a multidimensional array
    {
        // declare a 2-dimensional array
        int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

        display2DArray(matrix, 2);
        display2DArrayPtr(matrix, 2);
        display2DArrayUnknownSize(&matrix[0][0],
                                  sizeof(matrix) / sizeof(matrix[0]),
                                  sizeof(matrix[0]) / sizeof(*matrix[0]));

        int arr3D[][2][4] = {
            {{1, 2, 3, 4}, {5, 6, 7, 8}},
            {{9, 10, 11, 12}, {13, 14, 15, 16}},
            {{17, 18, 19, 20}, {21, 22, 23, 24}}
        };
        display3DArrayPtr(arr3D, 3);
    }


    // dynamically allocating a two-dimensional array
    {
        // allocating contigously memory
        int matrix[2][5] = {{1, 2, 3, 4, 6}, {6, 7, 8, 9, 10}};

        for (size_t i = 0; i < 2; i++) {
            for (size_t j = 0; j < 5; j++) {
                printf("matrix[%zu][%zu] Address: %p  Value: %d\n", i, j, &matrix[i][j], matrix[i][j]);
            }
            printf("\n");
        }

        // allocating potential noncontiguous memory
        {
            size_t rows = 2;
            size_t cols = 5;
    
            int **matrix = malloc(rows * sizeof(int *));
    
            for (size_t i = 0; i < rows; i++) {
                matrix[i] = malloc(cols * sizeof(int));
            }

            free(matrix);
        }

        // allocating contiguous memory
        {
            size_t rows = 2;
            size_t cols = 5;

            int **matrix = malloc(rows * sizeof(int*));

            matrix[0] = malloc(rows * cols * sizeof(int));

            for (size_t i = 1; i < rows; i++) {
                matrix[i] = matrix[0] + i * cols;
            }

            free(matrix);
        }

        // allocating contiguous memory
        {
            size_t rows = 2;
            size_t cols = 5;

            int *matrix = malloc(rows * cols * sizeof(int));

            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    *(matrix + (i * cols) + j) = i * j;
                }
            }

            free(matrix);
        }

        // jagged arrays and pointers
        {
            // 2 dimensional array with compound literals
            int *arr1[] = {
                (int[]) {0, 1, 2},
                (int[]) {3, 4, 5},
                (int[]) {6, 7, 8}
            };

            for (size_t i = 0; i < 3; i++) {
                for (size_t j = 0; j < 3; j++) {
                    printf("arr1[%zu][%zu] Address: %p  Value: %d\n", i, j, &arr1[i][j], arr1[i][j]);
                }
                printf("\n");
            }

            // 2 dimensinal jagged array with compound literals
            int *arr2[] = {
                (int[]) {0, 1, 2, 3},
                (int[]) {4, 5},
                (int[]) {6, 7, 8}
            };

            for (size_t i = 0; i < 4; i++) {
                printf("arr2[0][%zu] Address: %p  Value: %d\n", i, &arr2[0][i], *(arr2[0] + i));
            }
            printf("\n");
            for (size_t i = 0; i < 2; i++) {
                printf("arr2[1][%zu] Address: %p  Value: %d\n", i, &arr2[1][i], *(arr2[1] + i));
            }
            printf("\n");
            for (size_t i = 0; i < 3; i++) {
                printf("arr2[2][%zu] Address: %p  Value: %d\n", i, &arr2[2][i], arr2[2][i]);
            }
            printf("\n");
        }

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

        // test with unsigned char parameters
        unsigned char blar[] = {0x00, 0x01, 0x02, 0x03, 0x04};
        unsigned char blir[] = {0x00, 0x01, 0x02, 0x03, 0x04};
    
        if(safeCompare(blar, blir, sizeof(blar), sizeof(blir))) {
            printf("%s ungleich %s\n", "blar", "blir");
        } else {
            printf("%s gleich %s\n", "blar", "blir");
        }

        // test with unsigned char
        unsigned char blab = 0x00;
        unsigned char blib = 0x01;

        if(safeCompare(&blab, &blib, sizeof(blab), sizeof(blib))) {
            printf("%s ungleich %s\n", "blar", "blir");
        } else {
            printf("%s gleich %s\n", "blar", "blir");
        }

    }

    return 0;

}