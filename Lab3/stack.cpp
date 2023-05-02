#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


//functions implementation.
bool CreateStack(Stack *stack, int size){
    if(size <= 0){
        //which means the size is invaild.
        return false;
    }
    else{
        //declar an array to store the value of stack.
        stack -> values = (double*)malloc(sizeof(double)*size);
        //initialize the top of the stack.
        stack -> top = -1;
        //set the maxTop.
        stack -> maxTop = size -1;
        return true;
    }
}

bool IsEmpty(Stack *stack){
    if(stack -> top == -1){
        //which means the top is in the initial position.
        //so the stack is empty.
        return true;
    }
    else{
        //which means there is elements in the stack.
        return false;
    }
}

bool IsFull(Stack *stack){
    if(stack -> top == stack -> maxTop){
        //which means the stack is cannot store other values amymore.
        //so it is full.
        return true;
    }
    //otherwise, the stack is not full.
    return false;
}

bool Top(Stack *stack, double *x){
    //to return the value of the top of stack.
    if(IsEmpty(stack)){
        //which means the stack does not have any value,
        //so that we cannot assign value to x.
        return false;
    }
    //use dereferencing to assign value to x.
    *x = stack -> values[stack -> top];
    return true;
}

bool Push(Stack *stack, double x){
    //we need to check whether the stack is full.
    if(IsFull(stack)){
        //so that we cannot add any value into stack.
        return false;
    }
    else{
        //which means we can push elements.
        //the operation that pushing value is valid.
        stack -> values[++stack -> top] = x;
        return true;
    }
}

bool Pop(Stack *stack, double *x){
    //we need firstly check whether the stack is empty.
    if(IsEmpty(stack)){
        //which means there is no value that we can pop.
        return false;
    }
    //otherwise, we pass the value at the top to x.
    *x = stack -> values[stack -> top];
    //then decrease the top index.
    (stack -> top)--;
    return true;
}

void DisplayStack(Stack *stack){
    //we need to firstly check whether the stack is empty.
    if(stack == NULL){
        //printf("\n");
        return;
    }
    else if(IsEmpty(stack)){
        //which means the stack is no long have element.
        //just print a empty line.
        //printf("\n");
        return;
    }
    else{
        //declare a counter to decrease the index.
        int ind = stack -> top;
        while(ind != -1){
            printf("%f \n", stack -> values[ind]);
            ind--;
        }
        //printf("\n");
        return;
    }
}

void DestroyStack(Stack **pstack){

    /*
    //declare a pointer to store the stack's address.
    Stack *cStack = *pstack;
    //we need to check whether the stack is empty firstly.
    if(IsEmpty(cStack)){
        //so we can just set the pstack point to null.
        *pstack = NULL;
        return;
    }
    //otherwise, we need to do the pop first,
    //then delete the memory of values,
    //finall delete the memory of the stack structure.
    while(!IsEmpty(cStack)){
        Pop();
    }
    */
    //declare a pointer to store the stack's address.
    //Stack *cStack = *pstack;

    // while(IsEmpty(*pstack)){
    //     Pop(*pstack, cStack -> values);
    // }
    //then we can free the memory of values.
    free((*pstack) -> values);
    //or:
    //free(cStack -> values);
    //and free the stack structure;
    free(*pstack);
    //or:
    //free(cStack);
    //set the pstack point to NULL.
    *pstack = NULL;
    return;
}