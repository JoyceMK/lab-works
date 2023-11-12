#include<stdio.h>

void recurs_print(int ar[], int pos) {

    if(pos > 0)
        recurs_print(ar, pos-1);

    printf(" %d |",ar[pos]);
}

int main() {

    int ar[40], size, i, item;

    printf("Enter size of array (less than 40) : ");
    scanf("%d", &size);

    for (i = 0; i<size; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", &ar[i]);
    } 

    recurs_print(ar, size-1);

    return 0;
}
