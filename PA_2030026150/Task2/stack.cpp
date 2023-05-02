#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

bool CreateStack(Stack *stack, int size){
	if (size <= 0){
        //to decide the size is bigger than 0.
		return false;
	}
	stack ->values = (char*)malloc(sizeof(char)*size);//to assignment the memory to stack value
	stack->top = -1;
	stack->maxTop = size - 1;
	return true;
}

bool IsEmpty(Stack* stack){
	if (stack == NULL || (stack->top == -1 && stack->maxTop > 0)){
        return true;
    }
    return false;
}

bool IsFull(Stack* stack){
	if (stack == NULL || stack->top == stack->maxTop)
        return true;
    return false;
}

bool Push(Stack* stack, char x){
	if(IsFull(stack))
        return false;
    stack->values[++stack->top] = x;
    return true;
}

bool Pop(Stack* stack, char* x){
	if (IsEmpty(stack))
        return false;
    *x = stack->values[stack->top --];
    return true;
}

void DestroyStack(Stack** stack){
    if(stack == NULL){
        //which means the stack is empty.
        return;
    }
    Stack* top = *stack;
    if (top != NULL){
        if (top->values){
            free(top->values);
            top->values = NULL;
        }
        free(top);
    }
    *stack = NULL;
}

static inline bool Top(Stack* stack, char* x){
    if(stack == NULL){
        //which means the stack is empty.
        return false;
    }
    if (IsEmpty(stack))
        return false;
    *x = stack->values[stack->top];
    return true; 
}

//implement the function use stack.
bool ValidBrackets(char * str){
    if(str == NULL){
        //which means the string does not exist.
        return false;
    }
    //firstly check whether the length is vaild to pair.
    int len = strlen(str);
    if(len == 0){
        //which means the string exists but empty.
        return true;
    }
    if(len % 2 != 0){
        //it is obviously that we cannot pair the string,
        //juse return false.
        return false;
    }

    //declare a counter to check whether the result is valid.
    int counter = 0;
    //we need to initialize a stack firstly.
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack -> maxTop = 10000;
    stack -> top = -1;
    stack -> values = (char*)malloc(sizeof(char) * 9999);
    //push s[0] into stack.
    stack -> values[++stack -> top] = str[0];
    counter++;
    for(int i = 1; i < 10000; i++){
        if(str[i] == '\0'){
            //which means the s has already be scanned.
            break;
        }
        else if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            //which means we need to continue push element into stack.
            stack -> values[++stack -> top] = str[i];
            counter++;
        }
        else{
            //which means the we will pop the elements and see whether is correspond.
            switch(str[i]){
                case ')':
                    if(stack -> values[stack -> top] == '('){
                        stack -> top--;
                        counter++;
                        continue;
                    }
                    else{
                        return false;
                    }
                    break;
                case ']':
                    if(stack -> values[stack -> top] == '['){
                        stack -> top--;
                        counter++;
                        continue;
                    }
                    else{
                        return false;
                    }
                    break;
                case '}':
                    if(stack -> values[stack -> top] == '{'){
                        stack -> top--;
                        counter++;
                        continue;
                    }
                    else{
                        return false;
                    }
                    break;
                default:
                    // //else, push the element into stack again.
                    // stack -> values[++stack -> top] = s[i];
                    // counter++;
                    // continue;
                    return false;
                    break;
            }
        }
    }
    //free the memory.
    
    // if(counter == strlen(s) && counter % 2 == 0){
    //     //which means all elements is valid.
    //     return true;
    // }
    if(stack -> top == -1){
        free(stack -> values);
        free(stack);
        return true;
    }
    return false;
}

