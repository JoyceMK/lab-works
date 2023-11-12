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

int pop() {
    if(top == NULL) {
        printf("ERROR: Stack underflow.\n");
        return -1; 
    }
    stack *temp = top;
    top = top->next;
    return temp->data;
}



int main() {
    int ch, e;
    
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &e);
                push(e);
                break;
            case 2:
                e= pop();
                printf("Popped %d from the stack.\n", e);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 3);

    return 0;
}

