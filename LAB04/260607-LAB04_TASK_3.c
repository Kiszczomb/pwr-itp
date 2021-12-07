#include <stdio.h>
// I used infinite loop + break, because code is short and doesn't contain complicated nested loops;

int main() {
	int index = 0, even = 0, product, last[3] = {0};
	while(1) {
		// I used "hardcoded array shifting", because I know exacly size of array and it's small;
		last[0] = last[1];
		last[1] = last[2];
		// I'm using already existing array, because there's nbo need for additional variable;
		printf("Provide an integer number: "); scanf("%d", &last[2]); fflush(stdin);
		if(index == 0) product = last[2];
		else product *= last[2];
		if(last[2] % 2 == 0) even++;
		
		index++;

		if(product > 1000) {
			printf("Product of given numbers exeeded 1000\nQuiting...\n");
			break;
		}
		if(even > 10){
			printf("The number of reported even numbers exceed 10\nQuiting...\n"); // it will never occur for positive numbers, because 2^10 > 1000
			break;
		}
		if(last[0] == last[1] && last[1] == last[2]){
			printf("Three subsequent numbers had exactly the same value\nQuiting...\n"); 
			break;
		}
		char yn;
		printf("Do you want to finish? [Y/N] : "); scanf(" %c", &yn); fflush(stdin);
		if(yn == 'y' || yn == 'Y') break;

	}
	return 0;
}
