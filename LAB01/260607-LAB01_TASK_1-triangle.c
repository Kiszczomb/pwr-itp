/*
KACPER JASTRZĘBSKI - 260607
LAB01_TASK_1
*/

#include <stdio.h>
#include <math.h>

int main() {
	float a, b ,c;
	printf("Provide length of 3 sides of triangle:\n");
	printf("Side A: "); scanf("%f", &a);
	printf("Side B: "); scanf("%f", &b);
	printf("Side C: "); scanf("%f", &c);

	float perim = a + b + c;
	printf("===\nPerimeter = %f \n", perim);

	float semiperim = perim / 2;
	float area = sqrt (semiperim * (semiperim - a) * (semiperim - b) * (semiperim - c));
	printf("Area      = %f \n", area);

	return 0;
}
