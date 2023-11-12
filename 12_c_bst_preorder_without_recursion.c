#include <stdio.h>
#include <malloc.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node_stack {
    struct node* node;
    struct node_stack *next;
};
typedef struct node node;
typedef struct node_stack node_stack;
node *root = NULL;
node_stack *top = NULL;

void push(node *n) {
    node_stack *s = (node_stack *) malloc(sizeof(node_stack));
    s->node = n;
    s->next = top;
    top = s;
}

node* pop() {
    if(top == NULL) {
        return NULL;
    }
    node_stack *s = top;
    top = top->next;
    return s->node;
    
}

node *create_node(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(int data) {
    node *new_node = create_node(data);
    if (root == NULL) {
        root = new_node;
        return;
    }
    node *prev = NULL, *temp = root;
    while (temp != NULL) {
        prev = temp;
        if (temp->data > new_node->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (prev->data > new_node->data) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }
}

void preorder(node *n) {
    node *t;
    for(t = root; t!=NULL; t=t->left) {
        printf("%d, ", t->data);
        push(t);
    }
    t = pop();
    while(t!=NULL) {
        
        for(t = t->right; t!=NULL; t=t->left) {
            printf("%d, ", t->data);
            push(t);
        }
        t = pop();
    }
}

int main() {
    int opt, item;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (opt != 5);
}

