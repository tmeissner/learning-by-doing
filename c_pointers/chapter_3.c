#include <stdlib.h>
#include <stdio.h>


// macro for easier using of saferfree function
#define safeFree(p) saferFree((void**) &(p))


// typedefs
typedef int (*t_fptr)(int);
typedef int (*t_fptr_op)(int, int);
typedef void (*t_fptr_base)();


// function declarations
void allocateArray(int **arr, size_t size, int value);
void allocateArrayWrong(int *arr, int size, int value);
void saferFree(void **pointer);
int square(int num);
int add(int a, int b);
int sub(int a, int b);
//int err(int a, int b);
void err(void);
int operation(t_fptr_op op, int a, int b);
t_fptr_op select(int opc);
void initialiseOperationsArray(void);
int eval(int opc, int a, int b);
int evalArray(int opc, int a, int b);
t_fptr_op operations[128] = {NULL};



// pointer by reference
void allocateArray(int **arr, size_t size, int value) {
    int *array = (int*) malloc(size * sizeof(int));
    if (array != NULL) {
        for (size_t index = 0; index < size; index++) {
            array[index] = value;
        }
    }
    *arr = array;
}


// pointer by value -> this will not work
void allocateArrayWrong(int *arr, int size, int value) {
    arr = (int*) malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
}


// safer free version which checks for NULL pointer
// assigns NULL after freeing the pointer
// hint: check for null before free() isn't neccessary
void saferFree(void **pointer) {
    if (pointer != NULL && *pointer != NULL) {
        free(*pointer);
        *pointer = NULL;
    }
}


// simple (unsafe) addition function
int add(int a, int b) {
    return a + b;
}


// simple (unsafe) subtract function
int sub(int a, int b) {
    return a - b;
}


int operation(t_fptr_op op, int a, int b) {
    return op(a, b);
}


// simple (unsafe) square function
int square(int num) {
    return num * num;
}


// function selector
// returns pointer to selected function
t_fptr_op select(int opc) {
    switch (opc) {
        case '+': return add;
        case '-': return sub;
        default : return (t_fptr_op) err;
    }
}


// error function
void err(void) {  //int a, int b) {
    fprintf(stderr, "invalid operation!\n");
    //return 42;
}

// evaluate given operation on a & b
// operation is given by function pointer
int eval(int opc, int a, int b) {
    t_fptr_op operation = select(opc);
    return operation(a, b);
}


// initialise operations array
// with pointers to add & sub functions
void initialiseOperationsArray(void) {
    operations['+'] = add;
    operations['-'] = sub;
}


// eval function which works with
// the array of function pointers
int evalArray(int opc, int a, int b) {
    t_fptr_op operation;
    operation = operations[opc];
    return operation(a, b);
}


int main (void) {

    // variable definitions
    size_t size = 8;
    int value = 5;
    int *vector = NULL;
    //int (*fptr0) (int);
    t_fptr fptr0;

    // print vector address
    printf("before malloc: %p\n", vector);

    // function calls
    allocateArray(&vector, size, value);
    //allocateArrayWrong(vector_wrong, size, value);

    for (size_t index = 0; index < size; index++) {
        printf("%u : %d\n", (unsigned int) index, vector[index]);
    }

    // print vector address
    printf("before safeFree: %p\n", vector);

    //saferFree((void**)&(vector));
    safeFree(vector);

    // print vector address after free
    printf("after safeFree: %p\n", vector);

    // function pointer fptr0 now points to square()
    fptr0 = square;

    // call function which fptr0 points to
    printf("%d squared is %d\n", value, fptr0(value));

    // test of function pointers as function parameters
    printf("%u + %d = %d\n", (unsigned int) size, value, operation(add, size, value));
    printf("%u - %d = %d\n", (unsigned int) size, value, operation(sub, size, value));

    // test of fucntion pointer returning
    printf("%d\n", eval('t', size, value));

    // function pointer casting
    t_fptr_base basePointer;
    t_fptr_op fptrFirst = add;
    basePointer = (t_fptr_base) fptrFirst;
    fptrFirst = (t_fptr_op) basePointer;
    printf("%d\n", fptrFirst(5,6));

    // return value
    return 0;
}
