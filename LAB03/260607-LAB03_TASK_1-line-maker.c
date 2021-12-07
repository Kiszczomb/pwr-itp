#include <stdio.h>
#include <math.h>

int main() {

	char semigr[5] = {'-', '#', '@', '*', '&'};
	while(1){
		printf("LINE-MAKER v1.0\n\n");
		printf("Choose a character:\n");
		printf(" 1. a dash     : -\n");
		printf(" 2. a hash     : #\n");
		printf(" 3. a at sign  : @\n");
		printf(" 4. a asterisk : *\n");
		printf(" 5. a ampersand: &\n");
		printf(" 0. to exit \n\n");
	
		int menu;
		while(1) {
			printf("Select a number (0-5) : "); scanf("%d", &menu);
			if(menu >= 0 && menu <= 5) break;
			printf("[ERR] wrong value!\n");
		}
		if(menu == 0) break;
		printf("You selected: %c\n", semigr[menu-1]);
		int len;
		while(1) {
			printf("Provide a length of a line (a positive integer): "); scanf("%d", &len);
			if(len > 0) break;
			printf("[ERR] wrong value!\n");
		}
		printf("Your line:\n");
	
		switch(menu) {
			case 1:
				while(len--) {
					printf("%c", semigr[0]);
				}
				printf("\n");
				break;		
	
			case 2:
				len--;
				do {
					printf("%c", semigr[1]);		
				} while(len--);
				printf("\n");
				break;
				
			case 3:
				for(int i = len; i >= 1; i--) {
					printf("%c", semigr[2]);	
				}
					printf("\n");
			break;
				
		case 4:
				start:
				if(len == 0) goto finish;
				printf("%c", semigr[3]);
				len--;
				goto start;
				finish:
				printf("\n");
				break;
			
			case 5:
				start2:
				printf("%c", semigr[4]);
				len--;
				if(len > 0) goto start2;
				printf("\n");	
				break;
			
		}	
		printf("\n");
	}
	printf("\nBye bye!\n");
	return 0;
}	
