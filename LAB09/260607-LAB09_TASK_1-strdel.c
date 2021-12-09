#include <stdio.h>

// Functions prototypes:
char *strdel(char *text, int start, int len);

int main() {
    char test_str[] = "Hello in the city of Wroclaw!";
    
    printf("LAB09_TASK_1 - strdel()\n\n");
    printf("Examined string test_str[] = \"%s\"\n", test_str);
    printf("After strdel(test_str, 6, 15) = \"%s\"\n", strdel(test_str, 6, 15));

	return 0;
}

char *strdel(char *text, int start, int len) {
    while(text[start] != 0) {
        text[start] = text[start+len];
        start++;
    }
    return text;
}
