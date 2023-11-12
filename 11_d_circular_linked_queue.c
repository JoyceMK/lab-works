#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

struct node *create_node(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data) {
    struct node *newNode = create_node(data);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = rear->next;
    }
    rear->next = front; // Make the queue circular
    printf("Enqueued: %d\n", data);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return 0;
    }

    int data = front->data;
    if (front == rear) {
        front = rear = NULL;
    } else {
        rear->next = front->next;
        front = front->next;
    }
    printf("Dequeued: %d\n", data);
    return data;
}
int main() {
    int opt, data;
    do {
        printf("\n\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                break;
                
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (opt != 3);
    return 0;
}

