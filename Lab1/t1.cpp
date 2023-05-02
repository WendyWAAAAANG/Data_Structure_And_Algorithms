// #include <stdio.h>
// #include <string.h>
// int main(){
//     // //declare two variables to store the value input.
//     // int a = 0;
//     // int b = 0;
//     // //hint for input.
//     // printf("Please input two integers:\n");
//     // scanf("%d%d", &a, &b);
//     // printf("%d\n", a>b ? a: b);
//     // return 0;
//     char str[] = "Hello";
//     int i = strlen(str);
//     printf("%d", i);
//     return 0;
// }
#include <stdio.h>
int main(){
    //declare two variables to store the value input.
    int a = 0;
    int b = 0;
    //hint for input.
    printf("Please input two integers:\n");
    scanf("%d%d", &a, &b);
    printf("%d\n", a>b ? a: b);
    return 0;
}