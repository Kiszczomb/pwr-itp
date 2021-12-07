/*
260607
*/
#include <stdio.h>

int main() {
	printf("CHRISTMAS TREE v1.0\n\n");
	
	int height;
	printf("Provide a height of a tree (a positive integer): "); scanf("%d", &height);

	for(int i = 0; i < height; i++) {
		int space;
		for(space = height-i; space > 0; space--) {
			printf(" ");
		}

		for(int stars = 1; stars <= (2*i)+1; stars++ ) {
			printf("*");
		}
		printf("\n");
	}	
	for(int space = 0; space < height; space++) {
		printf(" ");
	}
	printf("#\n\nHO! HO! HO! MERRY CHRISTMAS!\n");
	return 0;
}
