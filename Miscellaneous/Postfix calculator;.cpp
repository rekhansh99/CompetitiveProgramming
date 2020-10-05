#include<stdio.h>
#include<string.h>
#define max 100
void push(int stack[], int *top, int data)
{
	if(*top < max-1)
	{
		stack[++(*top)] = data;
	}
}
int pop(int stack[], int *top)
{
	if(*top >= 0)
	{
		return (stack[(*top)--]);
	}
}
int postfix_evaluator(char str[], int len)
{
	int stack[max];
	int top = -1;
	for(int i=0; i<len; i++)
	{
		if(str[i] > 47 && str[i] < 58)
		{
			push(stack, &top, str[i]-48);
		}
		else
		{
			int op1, op2, res;
			op1 = pop(stack, &top);
			op2 = pop(stack, &top);
			switch(str[i])
			{
				case '+': res = op1 + op2;break;
				case '-': res = op1 - op2;break;
				case '*': res = op1 * op2;break;
				case '/': res = op1 / op2;break;
			}
			push(stack, &top, res);
		}
	}
	return (pop(stack, &top));
	
}
int main()
{
	char str[100];
	printf("Enter your postfix expression:");
	scanf("%s",str);
	int len = strlen(str);
	int value = postfix_evaluator(str, len);
	printf("Value of your postfix expression is : %d", value);
}

