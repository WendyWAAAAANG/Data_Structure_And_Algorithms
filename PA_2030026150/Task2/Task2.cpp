// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// //function declaration.
// bool ValidBrackets(char * str);
// //define a stack struct.
// typedef struct{
//     int maxTop;
//     int top;
//     char *values;
// } Stack;

// //main function.
// int main(){
//     char str[] = "(){}";
//     bool x = ValidBrackets(str);
//     printf("%d", x);
//     return 0;
// }

// //implement the function use stack.
// bool ValidBrackets(char * str){
//     //firstly check whether the length is vaild to pair.
//     int len = strlen(str);
//     if(len % 2 != 0){
//         return false;
//     }

//     //declare a counter to check whether the result is valid.
//     int counter = 0;
//     //we need to initialize a stack firstly.
//     Stack *stack = (Stack*)malloc(sizeof(Stack));
//     stack -> maxTop = 10000;
//     stack -> top = -1;
//     stack -> values = (char*)malloc(sizeof(char) * 9999);
//     //push s[0] into stack.
//     stack -> values[++stack -> top] = str[0];
//     counter++;
//     for(int i = 1; i < 10000; i++){
//         if(str[i] == '\0'){
//             //which means the s has already be scanned.
//             break;
//         }
//         else if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
//             //which means we need to continue push element into stack.
//             stack -> values[++stack -> top] = str[i];
//             counter++;
//         }
//         else{
//             //which means the we will pop the elements and see whether is correspond.
//             switch(str[i]){
//                 case ')':
//                     if(stack -> values[stack -> top] == '('){
//                         stack -> top--;
//                         counter++;
//                         continue;
//                     }
//                     else{
//                         return false;
//                     }
//                     break;
//                 case ']':
//                     if(stack -> values[stack -> top] == '['){
//                         stack -> top--;
//                         counter++;
//                         continue;
//                     }
//                     else{
//                         return false;
//                     }
//                     break;
//                 case '}':
//                     if(stack -> values[stack -> top] == '{'){
//                         stack -> top--;
//                         counter++;
//                         continue;
//                     }
//                     else{
//                         return false;
//                     }
//                     break;
//                 default:
//                     // //else, push the element into stack again.
//                     // stack -> values[++stack -> top] = s[i];
//                     // counter++;
//                     // continue;
//                     return false;
//                     break;
//             }
//         }
//     }
//     //free the memory.
    
//     // if(counter == strlen(s) && counter % 2 == 0){
//     //     //which means all elements is valid.
//     //     return true;
//     // }
//     if(stack -> top == -1){
//         free(stack -> values);
//         free(stack);
//         return true;
//     }
//     return false;
// }

