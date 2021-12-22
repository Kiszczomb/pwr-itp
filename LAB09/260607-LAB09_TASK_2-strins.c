#include <stdio.h>

// Functions prototypes:
char *strins(char *text, char *ins, unsigned int pos);

int main() {
    char *test_str = "Hello in Wroclaw!";
    
    printf("LAB09_TASK_2 - strins()\n\n");
    printf("Examined string test_str[] = \"%s\"\n", test_str);
    printf("After strins(test_str, \"The \", 9) = \"%s\"\n", strins(test_str, "The ", 9));

	return 0;
}

unsigned int strlenght(char *str) {
    char *count = str;
    while(*count != 0) count++;
    return (count-str)/sizeof(char);
}

char *strins(char *text, char *ins, unsigned int pos) {
    unsigned int text_len = strlenght(text);
    unsigned int ins_len = strlenght(ins);
    unsigned int len = text_len + ins_len;
    char result[len];

    int i = 0;
    while(i < len) {
       if(i < pos) result[i] = text[i];
       else if(i < pos + ins_len - 1) result[i] = ins[i-pos];
       else result[i] = text[i-ins_len];
       i++;
    }

    while(len--) {
         text[len] = result[len];
    }

    return text;
}
