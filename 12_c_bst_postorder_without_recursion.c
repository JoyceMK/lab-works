#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *right;
	struct node *left;
};
typedef struct node tree;
struct stack {
	int flag;
	tree *r;
	struct stack *next;
};
typedef struct stack stack;
stack *top=NULL;
tree *root=NULL;
void insert(int e) {
	tree *p,*x;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=e;
		root->left=root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data>e)
			   p=p->left;
			else
			  p=p->right;
		}
		if(x->data>e)
		{
			x->left=(tree*)malloc(sizeof(tree));
			x->left->data=e;
			x->left->right=x->left->left=NULL;
		}
		else
		{
			x->right=(tree*)malloc(sizeof(tree));
			x->right->data=e;
			x->right->right=x->right->left=NULL;
		}
	}
}

void push(tree *t,int f) {
   	stack *temp=(stack*)malloc(sizeof(stack));
   	temp->r=t;
   	temp->next=top;
   	temp->flag=f;
   	top=temp;
}

tree* pop() {
	tree *t=NULL;
	int f=0;
	if(top!=NULL)
	{
		t=top->r;
		if(top->flag==0)
		{
			f++;
			top=top->next;
		}
		else if(top->flag==1)
		{
			printf("\t%d",t->data);
			top=top->next;
			t=pop();
		}
	}
	if(f==1)
	  push(t,f);
	return t;
}

void postorder() {
	tree *t;
	for(t=root;t!=NULL;t=t->left)
	{
		push(t,0);
	}
	t=pop();
	while(t!=NULL)
	{
		for(t=t->right;t!=NULL;t=t->left)
		{
			push(t,0);
		}
		t=pop();
	}
}
int main() {
	int ch,e;
	do{
		printf("\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			    printf("\nEnter data: ");
				scanf("%d",&e);
				insert(e);
				break;
				
			case 2: 
			    printf("\n");
				postorder(root);
				printf("\n");
				break;		
		}
	}while(ch!=3);
	
	return 0;
}


