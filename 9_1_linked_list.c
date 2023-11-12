#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
	}
}


void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("list is empty");
	}
	else
	{
		t=head;
		printf("\n");
		while(t!=NULL){
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}


int menu()
{
	int ch;
	printf("\n1.Insert \n2.Display the Linked list \nEnter your choice :");
	scanf("%d",&ch);
	return(ch);
}

int main()
{
	int ch,e;
	for(ch=menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter element :");
					scanf("%d",&e);
					insert(e);
					break;
			case 2:display();
					break;
		}	
	}
	return 0;
}
