#include <stdio.h>

int main() {
	int index = 0;
	float sum = 0;
	float maxNum;
	float minNum;

	while(1) {
		float num;
		printf("Provide a number: "); scanf("%f", &num);
			
		sum += num;
		if(index == 0) minNum = maxNum = num;
		if(num > maxNum) maxNum = num;
		if(num < minNum) minNum = num;
		index++;

		char yn;
		printf("Do you want to finish? [Y/N] : "); scanf("%c", &yn);
		if(yn == 'y' || yn == 'Y') break;

	}
	float average = sum/(float)index;

	printf("\nYou provided %d numbers:\n", index);
	printf(" maximum            = %.2f \n", maxNum);
	printf(" minimum            = %.2f \n", minNum);
	printf(" sum                = %.2f \n", sum);
	printf(" arithmetic average = %.2f \n", average); 
	

	return 0;
}
