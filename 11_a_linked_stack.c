#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

typedef struct node stack;

stack *top=NULL;

void push(int e)
{
	stack *t=(stack *)malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop()
{
	if(top==NULL)
	{
		printf("\nLinked Stack is empty");
	}
	else{
		printf("%d\n",top->data);
		top=top->next;
	}
}

int main()
{
	push(10);
	push(20);
	pop();
	push(30);
	pop();
	pop();
}
