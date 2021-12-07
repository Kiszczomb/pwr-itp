/*
LAB02_TASK_03
260607
*/

#include <stdio.h>
#include <ctype.h>

int charToInt(char c) {
	return c-'0';
}

int main() {
	int nums[10][2] = {0};
	char given[4];
	printf("Provide 4 integers:\n");
	for(int i = 0; i <= 3; i++) {
		while(1) {
			printf("Integer nr %d: ", i+1);
			scanf("%s", &given[i]); // I used "%s" instead of " %c" to take only first digit of given number
			if(isdigit(given[i]) > 0) {
				nums[charToInt(given[i])][0]=1;
				nums[charToInt(given[i])][1]++;
				break;
			}
			printf("[ERR] This is not an integer!\n");
		}
	}
	
	printf("You provided followed integers:\n");
	for(int i = 0; i <= 9; i++) {
		if(nums[i][0]) {
			printf("Number %d - %d times\n", i, nums[i][1]);
		}
	}
	

	return 0;
}

