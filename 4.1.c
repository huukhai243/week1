#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<string.h>

struct Address
{
    char name[30];
    char number[30];
    char email[30];
};
void read_file(const char*fname,struct Address addr[])
{
	FILE*f=fopen(fname,"rt");
	if(f==NULL)
		return;
	else
	{
		int i=0;
		while(!feof(f))
		{
			fgets(addr[i].name,30,f);
			fgets(addr[i].number,30,f);
			fgets(addr[i].email,30,f);
			fscanf_s(f,"\n");
			i++;
		}		
	}
	fclose(f);
}
void write_file(const char*fname,struct Address addr)
{
	FILE*f=fopen(fname,"a");
	if(f==NULL)
		return;
	else
	{
		fprintf(f,"Name: %s", addr.name);
	    fprintf(f,"Telephone Number: %s", addr.number);
	    fprintf(f,"Email Address: %s\n", addr.email);
	}
	fclose(f);
}
typedef struct Stack
{
    int top;
    unsigned capacity;
    struct Address* list;
}Stack;

Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->list = (struct Address*)malloc(stack->capacity * sizeof(struct Address));
    return stack;
}


int Full(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int Empty(Stack* stack)
{
    return stack->top == -1;
}
void push(Stack* stack, struct Address address)
{
    if (Full(stack))
        return;
    stack->list[++stack->top] = address;
}
struct Address pop(Stack* stack)
{
    struct Address nothing;
    if (Empty(stack))
        return nothing;
    return stack->list[stack->top--];
}
struct Address peek(Stack* stack)
{
    struct Address nothing;
    if (Empty(stack))
        return nothing;
    return stack->list[stack->top];
}
int main()
{
    Stack* stack = createStack(100);
	struct Address addr[3];
	read_file("input.txt",addr);
	int i;
	for(i=0;i<3;i++)
	{
		push(stack,addr[i]);
	}
	
	for(i=0;i<3;i++)
	{
		write_file("output.txt",peek(stack));
		pop(stack);
	}
	
    return 0;
}

