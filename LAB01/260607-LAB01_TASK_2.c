/*
KACPER JASTRZĘBSKI - 260607
LAB01_TASK_2
*/

#include <stdio.h>
#include <math.h>

int main() {
	int select = 1;
	while(1) {
		printf("\n[MENU] Select subprogram: \n 1) Parameters of circle \n 2) Euclidean distance \n 3) EXIT \n\nSelect (1, 2 or 3): ");
		scanf("%d", &select);
		if (select == 1) {
			float r, circ, area;
			float pi = 3.141592653589;
			printf("Provide a radius of circle: "); scanf("%f", &r);
			circ = 2 * pi * r;
			area = pi * pow(r, 2.0);
			printf("===\n Circumference = %f \n", circ);
			printf(" Area          = %f \n===", area);
		}
		if (select == 2) {
			float x1, y1, x2, y2;
			printf("Provide a Cartesian coordinates: \n");
			printf("x1 : "); scanf("%f", &x1);
			printf("y1 : "); scanf("%f", &y1);
			printf("x2 : "); scanf("%f", &x2);
			printf("y2 : "); scanf("%f", &y2);
			float dist = sqrt( pow((x2-x1), 2.0) + pow((y2-y1), 2.0) );
			printf("===\n Distance between points A(%f; %f) and B(%f; %f) equals: %f \n", x1, y1, x2, y2, dist);

		}
		if (select == 3) { printf("Goodbye!\n"); return 0;}
	}
}
