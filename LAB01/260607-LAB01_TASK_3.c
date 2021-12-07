/*
KACPER JASTRZĘBSKI - 260607
LAB01_TASK_3
*/

#include <stdio.h>

int main() {
	float height;
	int clasify = 1;
	printf("Provide a height of a person: "); scanf("%f", &height);
	if (height > 150) {
		clasify = 2;
		if (height > 180) clasify = 3;
	}
	printf("According to our clasification height of this person is: ");
	if (clasify == 2) {
		printf("AVERAGE");
	}
	else if (clasify == 3) {
		printf("HIGH");
	} else {
		printf("LOW");
	}
	printf("\nGoodbye!\n");
	return 0;

}
