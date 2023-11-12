#include <stdio.h>
#include <string.h>
#define max 100
int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
			return 0;
	}
}
void infixToPostfix(char infix[max], char postfix[max])
{
	int i;
	int j=0;
	char opstack[max];
	char ch;
	int top=-1;
	for(i=0; infix[i]!='\0'; i++)
	{
		ch=infix[i];
		if(isalnum(ch))
		{
			postfix[j++]=ch;
		}
		else if(ch=='+' || ch=='*' || ch=='/' || ch=='-')
		{
			while(precedence(opstack[top]) >= precedence(ch) && top>=0)
			{
				postfix[j++]=opstack[top--];
			}
			opstack[++top]=ch;
		}
		else if(ch=='(')
		{
			opstack[++top]=ch;
		}
		else if(ch==')')
		{
			while(opstack[top]!='(' && top>=0)
			{
				postfix[j++]=opstack[top--];
			}
			top--;
		}
	}
	while(top>=0)
	{
		postfix[j++]=opstack[top--];
	}
	postfix[j]='\0';
}
int main()
{
	char infix[max], postfix[max];
	
	printf("Enter an infix expression: ");
	scanf("%s", infix);
	
	infixToPostfix(infix, postfix);
	printf("Postfix expression is %s", postfix);
	return 0;
	 
}
