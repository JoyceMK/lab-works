#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert_start(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else{
		t=head;
		t=(struct node *)malloc(sizeof(struct node));
		t->data=e;
		t->next=head;
		head=t;
	}
}

void insert_end(int e)
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

void insert_inter(int e)
{
	struct node *t,*t2;
	int num;
	if(head==NULL){
		printf("List is empty\n");
	}
	else
	{
		printf("Enter the element after which %d should be added :",e);
		scanf("%d",&num);
		t=head;
		while(t!=NULL && t->data!=num)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("%d not found",num);
		}
		else{
			t2=t->next;
			t->next=(struct node *)malloc(sizeof(struct node));
			t->next->data=e;
			t->next->next=t2;
		}
	}
	
}

void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Linked list is empty");
		
	}
	else{
		t=head;
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		 } 
	}
}

int menu()
{
	int ch;
	printf("\nLinked List Insertion\n");
	printf("**************");
	printf("\n\n1.Insert at start \n2.Insert at end \n3.Insert at intermediate \n4.Display the Linked list \nEnter your choice :");
	scanf("%d",&ch);
	return(ch);
}

int main()
{
	int ch,e;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter element :");
					scanf("%d",&e);
					insert_start(e);
					break;
			case 2:printf("Enter element :");
					scanf("%d",&e);
					insert_end(e);
					break;
			case 3:printf("Enter element :");
					scanf("%d",&e);
					insert_inter(e);
					break;
			case 4:disp();
					break;
			default:printf("Invalid Choice !!");
					break;
		}	
	}
	return 0;
}
