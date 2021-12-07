#include <stdio.h>  // standard libraries
#include <stdlib.h>
#include <string.h> // for memcpy()
#include <time.h>   // for rand() initialization

#define ARR_LIMIT 100
static const int arr_deafult_values[ARR_LIMIT] = {1, 4, -2, 3, 0, 9};

// function prototypes:
void insertSort();
void printArr();

// main function
int main() {
    srand(time(NULL));
    int arr_values[ARR_LIMIT];
    int arr_used_size = 6;
    printf("INSERTION SORT v1.0\n");
    // menu:
    int menu_choice;
    printf("Would you like array to be predefined or filled with random values?\n");
    printf("    1) predefined as {1, 4, -2, 3, 0, 9}\n");
    printf("    2) filled with random values from -100 to + 100\n");
    printf("Select [1 or 2] : ");
    scanf("%d", &menu_choice);

    if (menu_choice == 1)
        memcpy(arr_values, arr_deafult_values, sizeof(arr_deafult_values));
    else if (menu_choice == 2) {
        for (int i = 0; i < arr_used_size; i++) {
            // rand() reminder: (rand() % (50 - (-20) + 1)) + (-20)
            arr_values[i] = ((rand() % 201) - 100);
        }
    } else
        return 0;
    printArr(arr_values, arr_used_size);
    insertSort(arr_values, arr_used_size);
    printArr(arr_values, arr_used_size);

    return 0;
}

// functions declarations:

// Inser Sort
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

// Print Array
void printArr(int arr[ARR_LIMIT], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}