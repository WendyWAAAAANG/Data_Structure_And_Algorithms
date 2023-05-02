#include "stack.h"
#include <stdio.h>


static inline void _printResult(int ret){
    printf("%s\n", ret ? "True" : "False");
}

int main(void) {
	/* test cases */
	char str1[] = "{()[]}";
    char str2[] = "([)]";
    char str3[] = "{()}[";
    char str4[] = "";
    
    // printf("%d\n", ValidBrackets(str1));
    // printf("%d\n", ValidBrackets(str2));
    // printf("%d\n", ValidBrackets(str3));
    // printf("%d\n", ValidBrackets(str4));
    // printf("%d\n", ValidBrackets(NULL));

    _printResult(ValidBrackets(str1));
    _printResult(ValidBrackets(str2));
    _printResult(ValidBrackets(str3));
    _printResult(ValidBrackets(str4));
    _printResult(ValidBrackets(NULL));

}

/**************** sample output
True
False
False
True
False
*/