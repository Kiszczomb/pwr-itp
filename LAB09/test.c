#include <stdio.h>
// TODO: test this behavior from inside a function
char *modi(char *str, int pos, char ch) {
    char *ptr = str + pos;
    *ptr = ch;
    return str;
}

int main() {
    char arr[] = "Welcome to Wroclaw";
    printf("%s\n", arr);
    char *p_arr = &arr[0];

    printf("%c\n", *p_arr);
    p_arr+=2;
    *p_arr = 't';
    printf("%c\n", *p_arr);
    printf("%s\n", arr);
    printf("%s\n", modi(arr, 10 ,'\0'));
    
    return 0;
}

