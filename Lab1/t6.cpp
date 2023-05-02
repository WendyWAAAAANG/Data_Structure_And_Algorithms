#include <stdio.h>
#include <string.h>

//function decalration.
void reverseR(int length, char *str);

//function implementation.
int main(){
    //declare the variables.
    int len = 0;
    char str[50];
    //hint for input.
    printf("Please input a string:\n");
    scanf("%s", str);
    //store length of string into len.
    len = strlen(str);
    reverseR(len, str);
    //print out the result of the reverse string.
    printf("%s\n", str);
    return 0;
}

void reverseR(int length, char *str) {
    // length: the number of chars in *str
    // The chars in *str are reversed when
    // this fuction completes
    if(length == 0 || length == 1){
        //base case, nothing is done.
        return;
    }
    else{
        //which means teh string size is at least 2.
        //swap the first and last chars and reverse the remainder using recursion.
        char temp = str[0];
        str[0] = str[length-1];
        str[length-1] = temp;
        reverseR(length-2, str+1);
    }
    return;
}