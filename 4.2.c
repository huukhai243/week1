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
int precedence(char c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void infixToPostfix(char a[])
{
	char b[100] ;
	Stack*stack=createStack(100);
	int k=0;
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			b[k]=a[i];
			k++;
		}
		else if (a[i] == '(')
		{
			push(stack,a[i]);
		}
		else if (a[i] == ')')
		{
			while ((peek(stack) != '(') && (!Empty(stack)))
			{
				b[k++]=peek(stack);
				pop(stack);
			}
			if (peek(stack) == '(')
			{
				pop(stack);
			}
		}
		else if (a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			if (Empty(stack))
			{
				push(stack,a[i]);
			}
			else
			{
				if (precedence(a[i]) > precedence(peek(stack)))
				{
					push(stack,a[i]);
				}
				else
				{
					while ((!Empty(stack)) && (precedence(a[i]) <= precedence(peek(stack))))
					{
						b[k++]=peek(stack);
						pop(stack);
					}
					push(stack,a[i]);
				}
			}
		}
	}
	while (!Empty(stack))
	{
		b[k++]=peek(stack);
		pop(stack);
	}
	for(i=0;i<strlen(b);i++)
	{
		printf("%c ",b[i]);
	}
}
int main()
{
	char a[100];
	gets(a);
	infixToPostfix(a);
	return 0;
}



