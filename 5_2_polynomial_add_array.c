#include<stdio.h>
int i,j,n3;
int coefsum[10],expsum[10];

void display(int coef[], int exp[],int n)
{
	for(i=0;i<n;i++)
	{
		if(exp[i]==0)
		{
			printf("%d",coef[i]);
		}
		else
		{
			printf("%dx^%d",coef[i],exp[i]);
		}
		if(i!=n-1)
		{
			printf("+");
		}
	}
	printf("\n");
}

void read(int coef1[], int exp1[],int coef2[],int exp2[],int n1,int n2)
{
	
	printf("Enter first polynomial\n");
	for(i=0;i<n1;i++)
	{
		printf("Enter coef and exp of polynomial :");
		scanf("%d%d",&coef1[i],&exp1[i]);
	}
	
	printf("Enter second polynomial\n");
	for(i=0;i<n2;i++)
	{
		printf("Enter coef and expo of polynomial :");
		scanf("%d%d",&coef2[i],&exp2[i]);
	}
	printf("First polynomial:");
	display(coef1,exp1,n1);
	printf("\nSecond polynomial : ");
	display(coef2,exp2,n2);	

}

void add(int coef1[], int exp1[],int coef2[],int exp2[],int n1,int n2)
{
	int k=0;
	i=0;
	j=0;
	while(i<n1 && j<n2)
	{
		if(exp1[i]==exp2[j])
		{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i]+coef2[j];
			i++,j++,k++;
		}
		else if(exp1[i]<exp2[j])
		{
			expsum[k]=exp2[j];
			coefsum[k]=coef2[j];
			j++,k++;
		}
		else{
			expsum[k]=exp1[i];
			coefsum[k]=coef1[i];
			i++,k++;
		}
	}
	if(i<n1)
	{
		expsum[k]=exp1[i];
		coefsum[k]=coef1[i];
		i++,k++;
	}
	else if(j<n2)
	{
		expsum[k]=exp2[j];
		coefsum[k]=coef2[j];
		j++,k++;
	}
	n3=k;
	printf("Addition of polynomials : ");
	display(coefsum,expsum,n3);
}


int main()
{
	int n1,n2,coef1[10],exp1[10],coef2[10],exp2[10];
	printf("Enter the degree of first polynomials : ");
	scanf("%d",&n1);
	printf("Enter the degree of second polynomials : ");
	scanf("%d",&n2);
	read(coef1,exp1,coef2,exp2,n1,n2);
	add(coef1,exp1,coef2,exp2,n1,n2);

}
