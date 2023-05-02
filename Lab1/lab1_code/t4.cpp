#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int count = 0;
	char string[50];
	printf("Please enter a sentence: ");
	while (1) {
		scanf("%s", string);
		if (strcmp(string, "End") == 0) {
			break;
		}
		else {
			count = count + 1;
		}
	}
	printf("%d", count);
	system("pause");
}