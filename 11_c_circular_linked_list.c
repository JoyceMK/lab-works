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
	if(head==NULL){
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
	}
	else{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
	}
}

void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Circular linked list is empty");
	}
	else{
		t=head;
		printf("\n");
		do
		{
			printf("%d\t",t->data);
			t=t->next;	
		}while(t!=head);
		
	}
}

void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("Circular linked list is empty");
	}
	else if(head->data==e && head->next==head){
		head=NULL;
	}
	else if(head->data==e)
	{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=head->next;
		head=head->next;
	}
	else{
		t=head;
		while(t->next!=head && t->data!=e)
		{
			t=t->next;
		}
		if(t->next==head)
		{
			printf("\nElement not found");
		}
		else{
			t->next=t->next->next;
		}
	}
}




int main() {
	int opt, data;
	do{
		
		printf("\n\n1.Insert \n2.Display \n3.Exit \nEnter your option : ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				printf("Enter element : ");
				scanf("%d", &data);
				insert(data);
				break;
				
			case 2:
				display();
				break;
				
			case 3:
				break;
		}
	}while(opt!=3);
	
	return 0;
}

