#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data[100];
    struct node *left, *right;
};

typedef struct node node;
node *root = NULL;

node *create_node(const char *data) {
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->data, data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(const char *data) {
    node *new_node = create_node(data);
    if (root == NULL) {
        root = new_node;
        return;
    }
    node *prev = NULL, *temp = root;
    while (temp != NULL) {
        prev = temp;
        if (strcmp(temp->data, new_node->data) > 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (strcmp(prev->data, new_node->data) > 0) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }
}

void inorder(node *n) {
    if (n == NULL)
        return;
    inorder(n->left);
    printf("%s ", n->data);
    inorder(n->right);
}

int main() {
    int opt;
    char data[100];
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf(" %[^\n]", data);
                insert(data);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (opt != 3);
}

