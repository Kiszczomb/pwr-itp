#include <stdio.h>
#include <stdlib.h>

// Functions prototypes:

// The function:
//    char* superFormat( char* text )
//    should:
//    - trim leading spaces                    eg.    "___Los     Angeles    "
//    - trim trailing spaces                   eg.    "   Los     Angeles____"
//    - remove extra (multiple) blank spaces   eg.    "   Los ____Angeles    "
//    - change first letters of words to uppercase (capitalise)
//    - change following letters of words to lowercase
//    - ensure, that there is exactly one space after every dot "." or comma ","
//
//    Example call:
//       char textToModify[100] = "   dON'T                WOrry.be haPPY                ";
//       superFormat( textToModify );      //such a call of superFormat(...)
//       printf( "%s", textToModify );
//    will result with output: Don't Worry. Be Happy  
//
char *superFormat(char *text);

// str_cpt(char *str) - Capitalize a letter at beginning of a line and after every space.
char *str_cpt(char *str);

unsigned int str_len(char *str);

// str_triml(char *str) - Trim spaces from beginnig of a string
char *str_triml(char *str);

// str_trimr(char *str) - Trim spaces from end of a string
char *str_trimr(char *str);

// str_wsnorm() - Normalize white space (one space between words, and after dot "." or coma ",")
char *str_wsnorm(char *str);

int main() {
    char templ_str[] = "   dON'T                WOrry.be haPPY                ";
    char *work_str = &templ_str[0];
    
    printf("=== LAB09_TASK_3 - superFormat() ===\n\n");
    printf("Examined string templ_str[]  = \"%s\"\n", work_str);
    printf("String lenght = %d\n", str_len(work_str));

    work_str = str_triml(work_str);
    printf("After str_triml(templ_str)   = \"%s\"\n", work_str);

    work_str = str_trimr(work_str);
    printf("After str_trimr(templ_str)   = \"%s\"\n", work_str);
    
    work_str = str_wsnorm(work_str);
    printf("After str_wsnorm(templ_str)  = \"%s\"\n", work_str);

    work_str = str_cpt(work_str);
    printf("After str_cpt(templ_str)     = \"%s\"\n", work_str);

    printf("After superFormat(templ_str) = \"%s\"\n", superFormat(templ_str));

	return 0;
}

// str_len
unsigned int str_len(char *str) {
    char *count = str;
    while(*count != 0) count++;
    return (unsigned int)(count-str)/sizeof(char);
}

// str_triml(char *str) - Trim spaces from beginnig of a string
char *str_triml(char *str) {
    while(*str == 32) str++;
    return str;
}

// str_trimr(char *str) - Trim spaces from end of a string
char *str_trimr(char *str) {
    char *end = str + str_len(str) - 1;
    while(*end == 32) {
        *end = 0;
        end--;
    }
    return str;
}

// str_wsnorm() - Normalize white space (one space between words, and after dot "." or coma ",")
char *str_wsnorm(char *str) {
    int size = str_len(str);
    char *result = malloc(sizeof(char)*(size+1));
    int pos = 0;
    int res = 0;
    int space = 0;
    while(pos < size) {
        if(str[pos] == 32) {
            space = 1;
            pos++;
            continue;
        }
        else if(str[pos] == 46) {
            result[res] = 46;
            res++;
            pos++;
            space = 1;
        }
        if(space) {
            result[res] = 32;
            space = 0;
            res++;
        }
        result[res] = str[pos];
        res++;
        pos++;
        
    }
    result[pos] = 0;
    return result;
}

// str_cpt(char *str) - Capitalize a letter at beginning of a line and after every space.
char *str_cpt(char *str) {
    int size = str_len(str);
    char *result = malloc(sizeof(char)*(size+1));
    int pos = 0;
    int cpt = 1;

    while(pos < size) {
        char ch = str[pos];
        if(cpt && ch >= 97 && ch <= 122) ch -= 32;
        else if(!cpt && ch >= 65 && ch <= 90) ch += 32;
        cpt = 0;
        if(ch == 32) cpt = 1;
        result[pos] = ch;
        pos++;
    }
    result[pos] = 0;
    return result;
}


char *superFormat(char *text) {
       return str_cpt(str_wsnorm(str_triml(str_trimr(text))));
}


// str_trimr() - OLD IMPLEMENTATION:
/*
char *str_trimr(char *str) {
    int end = str_len(str) - 1;
    char *result = malloc(sizeof(char)*(end+1));
    
    while(str[end-1] == 32) end--;
    result[end] = 0;
    while(end--) result[end] = str[end];
   
    return result;
}
*/

