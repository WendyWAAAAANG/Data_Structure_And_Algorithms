#include <stdio.h>
//function declaration.
int sum(int num);

//function implementation.
int main(){
    //store the input number in n, store the sum in s.
    int n = 0;
    int s = 0;
    //hint for input.
    printf("Please input a positive number:\n");
    scanf("%d", &n);
    s = sum(n);
    //print out the result.
    printf("%d\n", s);
    return 0;
}
int sum(int num){
    //whether we add the if statement to avoid invaild input?
    if(num == 0){
        //base case.
        return 0;
    }
    else{
        //which means num is vaild.
        return num + sum(num - 1);
    }
}
