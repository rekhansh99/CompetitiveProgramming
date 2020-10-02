#include<stdio.h>
#include<string.h>
#define max 1000
void push(char stack[], int *top, char data)
{
	if(*top < max-1)
		stack[++(*top)] = data;
}
char pop(char stack[], int *top)
{
	if(*top >= 0)
		return (stack[(*top)--]);
}
int prec(char data)
{
	switch(data)
	{
		case '$': return 0;
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 3;
		case '^': return 4;
		case ')': return 5; 
	}
}
void infix_postfix(char str[], char postfix[], int len)
{
	int k=0;
	char stack[max];
	int top = -1;
	push(stack, &top, '$');
	for(int i=0; i<len; i++)
	{
		if(str[i] >= '1' && str[i] <= '9')
			postfix[k++] = str[i];
		else if(str[i] == '(')
			push(stack , &top, str[i]);
		else if(str[i] == ')')
		{
			char temp = pop(stack, &top);
			while(temp != '(')
			{
				postfix[k++] = temp;
				temp = pop(stack, &top);
			}
		}
		else
		{
			char temp = pop(stack, &top);
			if(prec(str[i]) > prec(temp))
			{
				push(stack, &top, temp);
				push(stack, &top, str[i]);
			}
			else if(prec(str[i] <= prec(temp)))
			{
				while(prec(temp) >= prec(str[i]))
				{
					postfix[k++] = temp;
					temp = pop(stack, &top);
				}
				push(stack, &top, temp);
				push(stack, &top, str[i]);
			}
		}
	}
	int temp;
	temp = pop(stack, &top);
	while(temp != '$')
	{
		postfix[k++] = temp;
		temp = pop(stack, &top);
	}
	postfix[k] = '\0';
}
int main()
{
	char str[1000];
	printf("Enter your infix expression:");
	scanf("%s",str);
	int len = strlen(str);
	char postfix[100];
	infix_postfix(str, postfix, len);
	printf("Your postfix expression is : ");
	printf("%s",postfix);
}
