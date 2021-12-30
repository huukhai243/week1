#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<string.h>
typedef struct Stack
{
    int top;
    unsigned capacity;
    char*c;
}Stack;
 
Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->c = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
 
 
int Full(Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int Empty(Stack* stack)
{   return stack->top == -1;  }
void push(Stack* stack, char item)
{
    if (Full(stack))
        return;
    stack->c[++stack->top] = item;
}
int pop(Stack* stack)
{
	char a;
    if (Empty(stack))
        return a;
    return stack->c[stack->top--];
}
int peek(Stack* stack)
{
	char a;
    if (Empty(stack))
        return a;
    return stack->c[stack->top];
}
void reverse_string(char s[])
{
	Stack*stack=createStack(100);
	int i;
	for(i=0;i<strlen(s);i++)
	{
		push(stack,s[i]);
	}
	for(i=0;i<strlen(s);i++)
	{
		s[i]=peek(stack);
		pop(stack);
	}
}
int main()
{
	char s[100];
	printf("Input string: ");
	gets(s);
	printf("Before reverse: %s",s);
	reverse_string(s);
	printf("\nAfter reverse: %s",s);
	return 0;
}



