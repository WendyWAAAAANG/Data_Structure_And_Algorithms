/* for Visual Studio users */
#include "stack.h" 
/* for VS code users */
//#include "stack.cpp" // for VS Code users
#include<stdio.h>
#include<stdlib.h>


int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	double val;
	CreateStack(stack, 5);
	Push(stack, 5);
	Push(stack, 6.5);
	Push(stack, -3);
	Push(stack, -8);
	DisplayStack(stack);
	if(Top(stack, &val))
		printf("Top: %.2f\n", val);
	Pop(stack, &val);
	if(Top(stack, &val))
		printf("Top: %.2f\n", val);
	while(!IsEmpty(stack))
		Pop(stack, &val);
	DisplayStack(stack);

	Push(stack,5);
	DisplayStack(stack);
	DestroyStack(&stack);
	DisplayStack(stack);
}