#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
node *push(node *top, int data)
{
	node *newn;
	newn = (node *)malloc(sizeof(node));
	newn->ptr = top;
	newn->data = data;
	return newn;
}
int pop(node **top)
{
	if(*top != NULL)
	{
		int temp;
		temp = (*top)->data;
		*top = (*top)->ptr;
		return temp;
	}
		return 404;
}
void stack()
{
	node *top = NULL;
	while(1)
	{
		printf("Enter you choice:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit and pop out all elements\n");
		int ans;
		scanf("%d",&ans);
		if(ans == 3)
		{
			printf("Your stack:\n");
			while(top != NULL)
			{
				printf("%d\n", pop(&top));
			}
			break;
		}
		switch(ans)
		{
			case 1: printf("Enter your value:");
					int val;
					scanf("%d",&val);
					top = push(top, val);
					break;
			case 2: val = pop(&top);
					printf("Your popped value is: %d", val);
					break;
		}		
	}

}
int main() 
{
	printf("Welcome to stack & link list incorrp:\n");
	stack();
	printf("Thanks for using our corp:");
}
