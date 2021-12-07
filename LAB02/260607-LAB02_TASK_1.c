#include <stdio.h>
#include <float.h>

int main() {
	int numint;
	double numdouble;
	char numchar;
	char text[30];
	int numbool;
	printf("Provide following data:\n1. A integer number       : "); scanf("%d", &numint);
	printf("2. A floating point number: "); scanf("%lf", &numdouble);
	printf("3. A single character     : "); scanf("%s", &numchar);
	printf("4. A sample text          : "); scanf("%s", text);
	while(1) {
		printf("5. A boolean (0 or 1)     : "); scanf("%d", &numbool);
		if(numbool == 0 || numbool == 1) break;
		printf("[ERR] %d is not a boolean value\n", numbool);
	}
	printf("You provided folowing data:\n");
	printf("1 - %15d \n", numint);
	printf("2 - %15.2lf \n", numdouble);
	printf("3 - %*c \n", 15, numchar);
	printf("4 - %*s \n", 15, text);
	printf("5 - %15d \n", numbool);

	return 0;
}
