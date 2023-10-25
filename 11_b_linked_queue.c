#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node queue;
queue *f,*r=NULL;

void enqueue(int e)
{
	queue *t;
	t=(queue *)malloc(sizeof(queue));
	t->data=e;
	t->next=NULL;
	if(f==NULL)
	{
		f=t;
		r=t;
	}
	else{
		r->next=t;
		r=t;
	}	
}

void dequeue()
{
	if(f==NULL)
	{
		printf("Linked queue is empty");
	}
	else{
		printf("%d",f->data);
		f=f->next;
		if(f==NULL)
		{
			r==NULL;
		}
	}
}


int menu()
{
	int ch;
	printf("\n1.Enqueue \n2.Dequeue \nEnter your choice :");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	int ch,el;
	for(ch=menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter number to be inserted :");
					scanf("%d",&el);
					enqueue(el);
					break;
			case 2:dequeue();
					break;
			default:printf("Invalid option !!!!");
		}
	}
	return 0;
}
