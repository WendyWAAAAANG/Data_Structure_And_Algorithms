#include <stdio.h>
int main(){
    //declare a variable to store the value of input.
    //initialize the g as 'x' for safe;
    char g = 'x';
    //hint for input.
    printf("Please input the GPA grade:\n");
    scanf("%c", &g);
    switch(g){
        case 'A':
            printf("4.00\n");
            break;
        case 'a':
            printf("4.00\n");
            break;
        case 'B':
            printf("3.00\n");
            break;
        case 'b':
            printf("3.00\n");
            break;
        case 'C':
            printf("2.00\n");
            break;
        case 'c':
            printf("2.00\n");
            break;
        case 'D':
            printf("1.00\n");
            break;
        case 'd':
            printf("1.00\n");
            break;
        case 'F':
            printf("0.00\n");
            break;
        case 'f':
            printf("0.00\n");
            break;
        default:
            printf("WARNING: Invalid Grade!");
            //!!default does not need break statement.
            //break;
    }
    return 0;
}