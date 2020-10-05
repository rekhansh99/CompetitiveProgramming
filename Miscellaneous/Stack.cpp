#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100
#define Esc 27
int stack[max];
int top = -1;
int pop()
{
	if(top >= 0)
		return(stack[top--]);
	else
		return(404);
}
void push(int data)
{
	if(top < max-1)
	{
		stack[++top] = data; 
	}
	else
		printf("Non feasible process!");
}
int main()
{
	printf("Welcome to stack org.\n");
	while(1)
	{
		printf("E'm what you want to perform :\n1. Push\n2. Pop\n3. Exit\n");
		int ans;
		fflush(stdin);
		scanf("%d",&ans);
		switch(ans)
		{
			case 1:
				int num;
				printf("Enter element to push into:");
				scanf("%d",&num);
				push(num);
				break;
			case 2:
				printf("Enter number of elements you want to pop out:");
				scanf("%d",&num);
				for(int i=0; i<num; i++)
				{
					int m = pop();
					if(m != 404)
						printf("%d\n",m);
					else	
					{
						printf("Error %d\n",m);
						break;
					}
				}
				break;
		}
		if(ans == 3)
		{
			printf("Thank you for using our org.\n");
			break;
		}
	}
}
