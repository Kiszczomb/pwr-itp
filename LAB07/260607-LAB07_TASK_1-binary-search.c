#include <stdio.h>  // standard libraries
#include <stdlib.h>
#include <string.h> // for memcpy()
#include <time.h>   // for rand() initialization

#define TRUE 1
#define ARR_LIMIT 100
static const int arr_deafult_values[ARR_LIMIT] = {1, 4, -2, 3, 0, 9};

// function prototypes:
void insertSort();
void printArr();
void randomArr();
int binarySearch();

// main function
int main() {
    srand(time(NULL));
    int arr_values[ARR_LIMIT];
    int arr_used_size = 6;
    printf("BINARY SEARCH v1.0\n");
    // menu:
    int menu_choice;
    printf("Would you like array to be predefined or filled with random values?\n");
    printf("    1) predefined as {1, 4, -2, 3, 0, 9}\n");
    printf("    2) filled with random values from -100 to + 100\n");
    int LOOP = 1;
    while (LOOP) {
        printf("Select [1 or 2] : ");
        scanf("%d", &menu_choice);
        fflush(stdin);

        switch (menu_choice) {
        case 1:
            memcpy(arr_values, arr_deafult_values, sizeof(arr_deafult_values));
            LOOP = 0;
            break;
        case 2:
            randomArr(arr_values, arr_used_size, -100, 100);
            LOOP = 0;
            break;
        default:
            break;
        }
        
    }
    printf("[INF] Provided array:\n");
    printArr(arr_values, arr_used_size);
    insertSort(arr_values, arr_used_size);
    printf("[INF] Sorted array:\n");
    printArr(arr_values, arr_used_size);

    int search_value;
    printf("Provide a value you'd like to search for : ");
    scanf("%d", &search_value);
    int found = binarySearch(arr_values, arr_used_size, search_value);
    if (found == -1)
        printf("Value %d not found!\n", search_value);
    else
        printf("Value '%d' found on position %d (zero-based numbering).\n", search_value, found);

    return 0;
}

// functions declarations:

// Inser Sort:
void insertSort(int arr[ARR_LIMIT], int arr_size) {
    int key;
    int j;
    for (int i = 1; i < arr_size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Print Array:
void printArr(int arr[ARR_LIMIT], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Initialize array with random values:
void randomArr(int arr[ARR_LIMIT], int arr_size, int min, int max) {
    for (int i = 0; i < arr_size; i++) {
        // rand() reminder: (rand() % (max - (min) + 1)) + (min)
        arr[i] = (rand() % (max - (min) + 1)) + (min);
    }
}

// Binary search (returns -1 if not found):
int binarySearch(int arr[ARR_LIMIT], int arr_size, int search) {
    int step = arr_size / 2;
    int pointer = step;
    int i = arr_size;
    while (i--) {
        if (arr[pointer] == search)
            return pointer;
        step = step / 2;
        if (search > arr[pointer]) {
            pointer += step;
        } else {
            pointer -= step;
        }
    }
    return -1;
}