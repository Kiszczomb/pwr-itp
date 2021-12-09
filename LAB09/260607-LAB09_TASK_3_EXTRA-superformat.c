#include <stdio.h>

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
// Functions prototypes:
char *superFormat(char *text);

int main() {
    char *test_str = "   dON'T                WOrry.be haPPY                ";
    
    printf("LAB09_TASK_3 - superFormat()\n\n");
    printf("Examined string test_str[]  = \"%s\"\n", test_str);
    printf("After superFormat(test_str) = \"%s\"\n", superFormat(test_str));

	return 0;
}


char *superFormat(char *text) {
    
}
