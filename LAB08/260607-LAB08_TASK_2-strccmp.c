// Kacper Jastrzebski - 260607
#include <stdio.h>

// Functions prototypes:
int strccmp(char *str1, char *str2, char ch);

int main() {
    char test_str1[] = "Hello World!";
    char test_str2[] = "Hello Wroclaw!";
    
    printf("LAB08_TASK02\n\nExamined strings: '%s' and '%s'\n", test_str1, test_str2);

    int check = strccmp(test_str1, test_str2, 'W');
    char *relation = check < 0 ? "precedes" : check > 0 ? "follows" : "equals";
    printf("strccmp(test_str1, test_str2, 'W') : %d -> test_str1 %s test_str2 until delimeter 'W'\n", check, relation);
    
    check = strccmp(test_str1, test_str2, '\0');
    relation = check < 0 ? "precedes" : check > 0 ? "follows" : "equals";
    printf("strccmp(test_str1, test_str2, '\\0') : %d -> test_str1 %s test_str2 until delimeter '\\0'\n", check, relation);
    
    check = strccmp(test_str1, test_str2, 'M');
    relation = check < 0 ? "precedes" : check > 0 ? "follows" : "equals";
    printf("strccmp(test_str1, test_str2, 'M') : %d -> test_str1 %s test_str2 until delimeter 'M'\n", check, relation);
    
    check = strccmp(test_str2, test_str1, 'c');
    relation = check < 0 ? "precedes" : check > 0 ? "follows" : "equals";
    printf("strccmp(test_str2, test_str1, 'c') : %d -> test_str2 %s test_str1 until delimeter 'c'\n", check, relation);
    
    return 0;
}

int strccmp(char *str1, char *str2, char ch) {
    int pos = 0;
    while(str1[pos] == str2[pos] && str1[pos] != 0 && str1[pos] != ch) pos++;
    if(str1[pos] != str2[pos]) return str1[pos]-str2[pos];
    return 0;
}
