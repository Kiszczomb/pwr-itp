#include <stdio.h>

int power(int num, int pow) {
	int begin = num;
	if(pow == 0) return 1;
	if(pow == 1) return num;
	while(pow>1) {
		num *= begin;
		pow--;
	}	
	return num;
}

int main() {
	int num, revers, pow = 0;	
	printf("INTEGER REVERSATOR v1.0\n\n");
	printf("Provide a multi-digit positive number: "); scanf("%d", &num);

	while(power(10,pow+1) < num) pow++;
	while(num > 0) {
		revers += (num % 10)*power(10, pow);
		num /= 10;
		pow--;
	}
	printf("Reversed: %d\n", revers);
	return 0;
}
