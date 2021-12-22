// Kacper Jastrzebski - 260607
#include <stdio.h>
#include <stdlib.h>

// Functions prototypes:
char *strcpt(char *str, int size);
int strlenght(char *str);

int main() {
    char test_str[] = "HelLo in tHE ciTy oF wroClaw!";
    
    printf("LAB08_TASK02\n\n");
    printf("Examined string test_str[] = \"%s\"\n", test_str);
    char *cpt_str = strcpt(test_str, strlenght(test_str));
    printf("After strcpt() : cpt_str[] = \"%s\"\n", cpt_str);
    
    return 0;
}

int strlenght(char *str) {
    int len = 0;
    while(str[len] != 0) len++;
    return len;
}

char *strcpt(char *str, int size) {
    char *result = malloc(sizeof(char)*(size+1));
    int pos = 0;
    int cpt = 1;

    while(str[pos] != 0) {
        char ch = str[pos];
        if(cpt && ch >= 97 && ch <= 122) ch -= 32;
        else if(!cpt && ch >= 65 && ch <= 90) ch += 32;
        cpt = 0;
        if(ch == 32) cpt = 1;
        result[pos] = ch;
        pos++;
    }
    return result;
}
