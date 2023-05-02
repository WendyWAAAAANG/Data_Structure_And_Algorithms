#include <stdio.h>
#include "stack.h"

bool CreateStack(Stack* stack, int size)
{
    if (size <= 0)
        return false;
    stack->values = (double*)malloc(sizeof(double) * size);
    stack->top = -1;
    stack->maxTop = size - 1;
    return true;
}

bool IsFull(Stack* stack)
{
    //if use IsFull, we need to check whether
    //stack pointer is NULL first.
    if(stack->top == stack->maxTop)
        return true;
    return false;
}

bool IsEmpty(Stack* stack)
{
    if (stack == NULL || (stack->top == -1 && stack->maxTop > 0))
    {
        return true;
    }
    return false;
}

bool Push(Stack* stack, double x)
{
    if (IsFull(stack))
        return false;
    stack->values[++stack->top] = x;
    return true;
}

bool Pop(Stack* stack, double* x)
{
    if (IsEmpty(stack))
        return false;
    *x = stack->values[stack->top --];
    return true;
}

bool Top(Stack* stack, double* x)
{
    if (IsEmpty(stack))
        return false;
    *x = stack->values[stack->top];
    return true; 
}

void DisplayStack(Stack* stack)
{
    if (IsEmpty(stack) == false)
    {
        int cur = stack->top;
        while (cur >= 0)
        {
            printf("%f\n", stack->values[cur -- ]);
        }
    }
}

void DestroyStack(Stack** stack)
{
    Stack* top = *stack;
    if (top != NULL)
    {
        if (top->values)
        {
            free(top->values);
            top->values = NULL;
        }
        free(top);
    }
    *stack = NULL;
}

