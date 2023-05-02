//method 1:
#include <stdio.h>
#include <string.h>
int main(){
    //declare a string to store the words in the sentence.
    char str[50];
    //char c;
    //declare a counter to store the num of words.
    int counter = 0;
    //hint for input.
    printf("Please input a line of sentence:\n");
    //store the input.
    gets(str);
    for(int i = 0; i < strlen(str); i++){
        //c = getchar();
        if(str[i] == ' '){
            //which means one word ends.
            counter++;
        }
        else if(str[i] == 'E'){
            //to futher check whether the string is "End".
            if(str[i+1] == 'n' && str[i+2] == 'd'){
                //if so, the process should be ended.
                break;
            }
        }else{
            //continue to scan the words.
            continue;
        }
    }
    printf("%d\n", counter);
    return 0;
}



// //method 2:
// #include <stdio.h>
// #include <string.h>
// int main(){
//     //declare a string to store the words in the sentence.
//     char str[50][50];
//     //char c;
//     //declare a counter to store the num of words.
//     int counter = 1;
//     //hint for input.
//     printf("Please input a line of sentence:\n");
//     //store the input.
//     //gets(str);
//     for(int i = 0; i < 50; i++){
//         //c = getchar();
//         scanf("%s", str[i]);
//         if(strcmp(str[i], "End") == 1){
//             break;
//         }
//         else{
//             counter++;
//             continue;
//         }
//     }
//     printf("%d\n", counter);
//     return 0;
// }



// //method 3:
// #include <stdio.h>
// #include <string.h>
// int main(){
//     char str[50];
//     int counter = 0;
//     //hint for input.
//     printf("Please input a line of sentence:\n");
//     for(int i = 0; i < 50; i++){
//         scanf("%s", str);
//         if(strcmp(str, "End") == 0){
//             //which means the sentence will not end.
//             counter++;
//         }
//         else{
//             break;
//         }
//     }
//     printf("%d", counter);
//     return 0;
// }