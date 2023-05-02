#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>

//task2
int main() {
	char grade;
	printf("If GPA is ");
	scanf("%c", &grade);
	switch (grade) {
	case 'A': printf("4.00");
		break;
	case 'a': printf("4.00");
		break;
	case 'B': printf("3.00");
		break;
	case 'b': printf("3.00");
		break;
	case 'C': printf("2.00");
		break;
	case 'c': printf("2.00");
		break;
	case 'D': printf("1.00");
		break;
	case 'd': printf("1.00");
		break;
	case 'F': printf("3.00");
		break;
	case 'f': printf("3.00");
		break;
	default: printf("Invalid grade!!!");
		break;
	}
	system("pause");
}