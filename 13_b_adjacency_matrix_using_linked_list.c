#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Vertex {
    struct Node* adjList;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Vertex* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src].adjList;
    graph[src].adjList = newNode;
}

void printAdjacencyMatrix(struct Vertex* graph, int vertices) {
    printf("Adjacency Matrix:\n");
    int i,j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            int isAdjacent = 0;
            struct Node* currentNode = graph[i].adjList;
            while (currentNode != NULL) {
                if (currentNode->vertex == j) {
                    isAdjacent = 1;
                    break;
                }
                currentNode = currentNode->next;
            }
            printf("%d ", isAdjacent);
        }
        printf("\n");
    }
}

int main() {
    int vertices,i;
    char s, d;
    printf("How many vertices do you have: ");
    scanf("%d", &vertices);

    struct Vertex graph[vertices];
	
    for ( i = 0; i < vertices; i++) {
        graph[i].adjList = NULL;
    }

    printf("Enter vertices with an edge in between - separated (0 to stop):\n");
    do {
        scanf(" %c-%c", &s, &d);
        if (s == '0') {
            break;
        }

        int source = s - 'a';
        int destination = d - 'a';
        addEdge(graph, source, destination);
    } while (1);

    printAdjacencyMatrix(graph, vertices);


    return 0;
}

