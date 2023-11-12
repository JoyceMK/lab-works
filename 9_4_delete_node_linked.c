#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node node;

struct node *head;
struct node* create_node(int data) {
	
	struct node *newNode = ( struct node* )malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insert(int data) {
	struct node *temp, *newNode = create_node(data);
	if(head == NULL) {
		head = newNode;
		return;
	}
	temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	return;
}

void delete_first() {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    head = head->next;
}

void delete_last() {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node *current = head, *prev = NULL;
    if(head->next == NULL) {
        head = NULL;
        return;
    }
    while(current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
}

void delete_element(int el) {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    node *prev = NULL, *current = head;
    while(current != NULL && current->data != el) {
        prev = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Element not found");
        return;
    }
    if(prev == NULL) {
        head = head->next;
        return;
    }
    
    prev->next = current->next;
}

void display() {
	struct node* temp = head;
	printf("\n\n");
	while(temp != NULL) {
		printf("%d\t", temp->data );
		temp = temp->next;
	}
}

int main() {
	int ch,e;
	do{
		printf("\n\n1.Insert \n2.Display \n3.Delete first \n4.Delete last \n5.Delete element \n6.Exit \nEnter your option : ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				printf("Enter element : ");
				scanf("%d", &e);
				insert(e);
				break;
				
			case 2:
				display();
				break;
				
			case 3:
			     delete_first();
			     break;
			 
			case 4:
			    delete_last();
			    break;
			    
			case 5:
			    printf("Enter element to delete : ");
			    scanf("%d", &e);
			    delete_element(e);
			    break;
			
		}
	}while(ch!=6);
	return 0;
	
}

