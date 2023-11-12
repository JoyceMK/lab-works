#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *left, *right;
};
typedef struct node node;
node *root = NULL;

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

void inorder(node *n) {
    if (n == NULL)
        return;
    inorder(n->left);
    printf("%d ", n->data);
    inorder(n->right);
}

void preorder(node *n) {
    if (n == NULL)
        return;
    printf("%d ", n->data);
    preorder(n->left);
    preorder(n->right);
}

void postorder(node *n) {
    if (n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    printf("%d ", n->data);
}

int main() {
    int opt, item;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (opt != 5);
}

