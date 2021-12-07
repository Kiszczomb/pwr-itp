// Kacper Jastrzebski - 260607
#include <stdio.h>

// Functions prototypes:
int mystrlen(char *str);
int mystrchr(char *str, char ch);

int main() {
    char test_str1[] = "Hello World!";
    
    printf("LAB08_TASK01\n\nExamined string: '%s'\n", test_str1);
    printf("mystrlen(test_str1)      : %d \n", mystrlen(test_str1));
    printf("mystrchr(test_str1, 'W') : %d \n", mystrchr(test_str1, 'W'));
    printf("mystrchr(test_str1, 'M') : %d \n", mystrchr(test_str1, 'M'));
    return 0;
}

int mystrlen(char *str) {
    int len = 0;
    while(str[len] != 0) len++;
    return len;
}
        
// returns -1 if not found, else return position
int mystrchr(char *str, char ch) {
    int pos = 0;
    while(str[pos] != 0 && str[pos] != ch) pos++;
    if(str[pos] == 0) return -1;
    return pos;
}
