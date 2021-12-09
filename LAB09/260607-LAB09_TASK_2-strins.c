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

char *strins(char *text, char *ins, unsigned int pos) {
    int text_len = 0;
    while(text[text_len] != 0) text_len++;
    int ins_len = 0;
    while(ins[ins_len] != 0) ins_len++;
    char result[text_len+ins_len];

    int i = 0;
    while(i < text_len + ins_len) {
       if(i < pos) result[i] = text[i];
       else if(i < pos + ins_len - 1) result[i] = ins[i-pos];
       else result[i] = text[i-ins_len];
       i++;   
    }
    text = result;    
    return text;
}
