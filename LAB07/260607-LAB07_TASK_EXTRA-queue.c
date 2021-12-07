/*
 * Kacper Jastrzebski
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants definition
#define TRUE 1
#define FALSE 0
#define ARR_LIMIT 100
#define ARR_NAME_LIMIT 20

// Makro for array intialization with default values:
#define newArr(X) \
    ARRAY X; \
    X.size = 0; \
    strcpy(X.name, #X)

// ARRAY structure declaration
typedef struct {
    char name[ARR_NAME_LIMIT];
    int values[ARR_LIMIT];
    int size;
} ARRAY;

// ARRAY Fuctions prototypes:
int arrPop(ARRAY *arr);
int arrPush(ARRAY *arr, int value);
int arrIsEmpty(ARRAY *arr);
void arrPrint(ARRAY *arr);
int arrInsert(ARRAY *arr, int value, int position); 
int arrRemove(ARRAY *arr, int position); 
void goodbye();

// === Main function
int main() {
    atexit(goodbye);       
    printf("QUEUE IMPLEMENTATION v1.3\n\n");
    
    printf("[INF] Create new empty layer. Check isArrEmpty(). Print array:\n");
    newArr(arr1);
    
    printf(arrIsEmpty(&arr1) ? "TRUE\n" : "FALSE\n");
    
    arrPrint(&arr1);

    printf("[INF] Push 4, 3, 9 onto array (stack). Print array:\n");
    arrPush(&arr1, 4);
    arrPush(&arr1, 3);
    arrPush(&arr1, 9);
    
    arrPrint(&arr1);

    printf("[INF] Pop two last elements. Print array:\n");
    arrPop(&arr1);
    arrPop(&arr1);
    
    arrPrint(&arr1);

    printf("[INF] Push 2, 6, 4 onto array (stack). Print array:\n");
    arrPush(&arr1, 2);
    arrPush(&arr1, 6);
    arrPush(&arr1, 4);

    arrPrint(&arr1);

    printf("[INF] Insert 7 at position 1. Print array:\n");
    arrInsert(&arr1, 7, 1);

    arrPrint(&arr1);

    printf("[INF] Remove element from position 2. Print array:\n");
    arrRemove(&arr1, 2);

    arrPrint(&arr1);

    exit(0);
    return 0;
}

// pop() function implementation:
int arrPop(ARRAY *arr) {
    if(arr->size > 0) {
        arr->values[arr->size] = 0;
        arr->size--;
        return TRUE;
    }
    // If array empty:
    return FALSE;
}

// push() function implementation:
int arrPush(ARRAY *arr, int value) {
    if(arr->size < ARR_LIMIT) {
        arr->values[arr->size] = value;
        arr->size++;
        return TRUE;
    }
    // If ARR_LIMIT exceeded:
    return FALSE;
}

// isEmpty() function implemetation:
int arrIsEmpty(ARRAY *arr) {
    if(arr->size > 0) return FALSE;
    return TRUE;
}

// === Other ARRAY "methods" implemeted:

// arrPrint(ARRAY *arr) - prints all array elements
void arrPrint(ARRAY *arr) {
    if(arr->size == 0) printf("Array '%s' is empty, nothing to print\n", arr->name);
    else {
        printf("%s = { ", arr->name);
        for(int i = 0; i < arr->size; i++) {
            printf("%d", arr->values[i]);
            if(i < arr->size-1) printf(", ");
        }
        printf(" }\n");
    }
}

/* TODO: Loop instead of recurention. Reason: more efficient (less if's) */
// arrInsert(ARRAY *arr, int value, int position) - insert value at position, shift rest of values right
int arrInsert(ARRAY *arr, int value, int position) {
    if(position >= 0) {
        if(position == arr->size) return arrPush(arr, value);
        else if(position < arr->size) {
            int cur_value = arr->values[position];
            arr->values[position] = value;
            arrInsert(arr, cur_value, position+1);
        }
    }
    return FALSE;
}

// arrRemove(int position) - remove element from position, shift rest of values left
int arrRemove(ARRAY *arr, int position) {
    if(position >= 0) {
        if(position <= arr->size-1) {
            for(position; position < arr->size-1; position++) {
                arr->values[position] = arr->values[position+1];
            }
            arrPop(arr);
            return TRUE;
        }
    }
    return FALSE;
}


// === Other functions:

// Goodbye function to call at exit"
void goodbye() {
    printf("\nGoodbye!\n");
}








