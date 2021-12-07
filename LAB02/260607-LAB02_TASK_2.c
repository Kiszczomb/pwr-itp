/*
260607 - Kacper Jastrzebski
LAB02_TASK_2
*/

#include <stdio.h>
#include <math.h>

int main() {
	int res = 2;
	int year1, month1, day1, year2, month2, day2;
	printf("Provide first date: \n");
	printf("Year [YYYY]: "); scanf("%d", &year1);
	printf("Month  [MM]: "); scanf("%d", &month1);
	printf("Day    [DD]: "); scanf("%d", &day1);
	printf("Provide second date: \n");
	printf("Year [YYYY]: "); scanf("%d", &year2);
	printf("Month  [MM]: "); scanf("%d", &month2);
	printf("Day    [DD]: "); scanf("%d", &day2);

	if(year1 > year2) {
		res = 1;
	}
	else if(year1 == year2) {
		if(month1 > month2) {
			res = 1;
		}
		else if (month1 == month2) {
			if(day1 > day2) {
				res = 1;
			}
			else if(day1 == day2) {
				res = 3;
			}
		}
	}
	if(res == 1) printf("First date is earlier\n");
	else if(res == 2) printf("Second date is earlier\n");
	else if(res == 3) printf("Provided dates are equal\n");

	return 0;
}
