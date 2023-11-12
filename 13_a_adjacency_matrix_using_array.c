#include<stdio.h>
#include<malloc.h>

int** makeAdjacencyMatrix(int n) {
    int i;
    int **ad_matrix = (int**) malloc(sizeof(int*)*n);
    for(i=0;i<n;i++) {
        ad_matrix[i] = (int*) calloc(n, sizeof(int));
    }
    return ad_matrix;
}
void printMatrix(int **mat, int n) {
    
    int i,j;
    for(i=0;i<n;i++) {
        printf(" %c", 'a'+i);
    }

    for(i=0;i<n;i++) {
        printf("\n%c ", 'a'+ i);
        for(j=0;j<n;j++) {
            printf("%d ", mat[i][j]);
        }
    }
}
int main() {
    
    int **ad_matrix, i, n;
    char s, d;
    printf("How many vertices do you have : ");
    scanf("%d", &n);
    
    ad_matrix = makeAdjacencyMatrix(n);
    
    printf("Enter vertices with an edge in between - seperated (a-d)\nenter 0 to stop:\n");
    do {
        scanf(" %c-%c", &s, &d);
        if(s == '0') 
            break;
            
        ad_matrix[s - 'a'][d - 'a'] = 1;
    }while(1);
    
    printf("\nAdjacency matrix will look like : \n\n");
    printMatrix(ad_matrix, n);
}

