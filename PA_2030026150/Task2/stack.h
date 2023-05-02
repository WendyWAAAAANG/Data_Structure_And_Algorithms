#include <stdlib.h>

typedef struct Stack
{
   char* values;
   int top;
   int maxTop;
} Stack;

bool CreateStack(Stack* stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Push(Stack* stack, char x);
bool Pop(Stack* stack, char* x);
void DestroyStack(Stack** stack);
bool ValidBrackets(char* str);
