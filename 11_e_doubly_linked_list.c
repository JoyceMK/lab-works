#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
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
		head->prev=NULL;
	}
	else{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
		t->next->prev=t;
	}
}

void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nDoubly linked list is empty");
	}
	else{
		t=head;
		printf("\n");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nDoubly linked list is empty");
	}
	else if(head->next==NULL && head->data==e)
	{
		head=NULL;
	}
	else if(head->data==e)
	{
		head=head->next;
		head->prev=NULL;
	}
	else{
		t=head;
		while(t!=NULL && t->data!=e)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("\nElement not found");
		}
		else if(t->next==NULL)
		{
			t->prev->next=NULL;
		}
		else{
			t->prev->next=t->next;
			t->next->prev=t->prev;
		}
	}
}

int main() {
    int opt, data;
    do {
        printf("\n1.Insert \n2.Display \n3.Delete \nEnter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                display();
                break;
			case 3:
                printf("Enter element: ");
                scanf("%d", &data);
                delete(data);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (opt != 4);

    return 0;
}

