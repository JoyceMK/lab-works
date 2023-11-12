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
	if(head == NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head -> data = e;
		head -> next = NULL;
    }
    else
    {
    	t=head;
    	while(t->next!=NULL)
    	{
    		t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
	}	
}
void disp()
{
	struct node *t;
	if (head==NULL)
		printf("Linked list is empty!!\n\n");
	else
	{
		t=head;
		printf("\n");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
		printf("\n");
	}		
}





void reverse()
{
    struct node *t,*temp1,*temp2;
    int i=0;
    if(head == NULL)
    {
        printf("\nLinked List is empty!!!\n\n");
    }
    else
    {
        t=head;
        temp2=NULL;
        while(t!=NULL)
        {
            temp1 = t;
            t=t->next;
            temp1->next = temp2;
            temp2 = temp1;
        }
        head = temp2;
    }
    printf("\nThe linked list is reversed\n\n");
}


int menu()
{
	int ch;
	printf("1. Insert\n2. Print Reverse Order\n3. Display\n4. EXIT\n\n");
	printf("Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}
int main ()
{
	int ch;
	for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter the element to insert : ");
					 scanf("%d",&ch);
					 insert(ch);
                     break;
            case 2 : reverse();
                     break;
            case 3 : disp();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
        printf("\n");
    }
}
