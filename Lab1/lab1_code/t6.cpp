#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void reverseR(int length, char* str){
    char temp;
    int left = 0, right = length - 1;
    while (left < right) {
        temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
}

int main() {
    char string[50];
    printf("Please enter a String:");
    scanf("%s",&string);
    int len = strlen(string);
    reverseR(len, string);
    printf("%s", string);
    system("pause");
}