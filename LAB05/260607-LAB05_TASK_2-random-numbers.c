#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("RANDOM-NUMBERS-STORED-IN-ARRAY-inator 2000 v1.0\n\n");
    printf("Array contains values from -20 to +50 as follows:\n");
    srand(time(NULL));
    int isAscend = 0;
    while (isAscend == 0) {
		
        int array[10];
        int isAscend = 1;
        for (int i = 0; i < 10; i++) {
            array[i] = (rand() % (50 - (-20) + 1)) + (-20);
            printf("%d, ", array[i]);
            if (i >= 1) {
                if (array[i] >= array[i - 1])
                    isAscend = 0;
            }
        }
        printf("\n");
    }
    printf("Array is ascending!\n");
    return 0;
}
