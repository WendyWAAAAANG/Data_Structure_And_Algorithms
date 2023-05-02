#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
int main(){
    //declare a string to store the input,
    //and a integer to store the length of string.
    char str[50];
    int lenOfString = 0;
    //hint for input.
    printf("Please input a string:\n");
    scanf("%s", str);
    //Assign length of string to int.
    lenOfString = strlen(str);
    printf("%d\n", lenOfString);
    return 0;
}