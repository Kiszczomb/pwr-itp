#include <stdio.h>
#include <time.h>   // for time()
#include <stdlib.h> // for srand()

#define BLOCK_SIZE 10

// Functions prototypes:
double *arr_init(unsigned int size);
double *arr_rand(double *arr, unsigned int arr_size, int min, int max);
double *arr_print(double *arr, unsigned int arr_size);
double *arr_extremes(double *arr, unsigned int arr_size, double *min, double *max);

int main() {
    srand(time(NULL));
    int loop = 1;

    while(loop) {
        unsigned int size = 0;

        printf("How many elements would you like to store? : ");
        scanf("%d", &size);

        double *my_arr = arr_init(size);

        printf("Would you like to initialize an array with random numbers between 0 and 100? [Y/N] : ");
        char yn;
        scanf(" %c", &yn);
        fflush(stdin);

        if(yn == 'y' || yn == 'Y') arr_rand(my_arr, size, 0, 100);
        else {
            for(int i = 0; i < size; i++) {
                printf("Provide element nr %d : ", i);
                scanf("%lf", my_arr+i);
            }
        }
        arr_print(my_arr, size);
        double min, max;
        arr_extremes(my_arr, size, &min, &max);
        printf("MIN: %lf, MAX: %lf \n", min, max);
        free(my_arr);

        printf("Would you like to run program again? [Y/N] : ");
        scanf(" %c", &yn);
        if(yn == 'n' || yn == 'N') loop = 0;

    }
    printf("Goodbye!\n");
    return 0;
}

double *arr_init(unsigned int size) {   
    unsigned int alloc_size = ((size / BLOCK_SIZE) + 1 ) * BLOCK_SIZE;
    double *arr = NULL;
    arr = (double*) calloc(alloc_size, sizeof(double));
    return arr;
}

double *arr_rand(double *arr, unsigned int arr_size, int min, int max) {
    for(int i = 0; i < arr_size; i++) {
        arr[i] = (double)(rand() % (max - (min) + 1)) + (min);
    }
    return arr;
}

double *arr_print(double *arr, unsigned int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        printf("[%d] = %lf \n", i, arr[i]);
    }
    return arr;
}

double *arr_extremes(double *arr, unsigned int arr_size, double *min, double *max) {
    for(int i = 0; i < arr_size; i++) {
        if(i == 0) {
            *max = arr[i];
            *min = arr[i];
            continue;
        }
        if(arr[i] > *max) *max = arr[i];
        if(arr[i] < *min) *min = arr[i];
    }
    return arr;
}
