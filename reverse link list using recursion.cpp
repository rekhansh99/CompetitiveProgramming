#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
node * create_list()
{
	node *curr, *prev;
	node *start = (node *)malloc(sizeof(node));
	int i = 1;
//	printf("Enter your %d element: ", i++);
	scanf("%d",&(start->data));
	prev = start;
	int val = 0;
	while(prev->data != -1)
	{
		curr = (node *)malloc(sizeof(node));
//		printf("Enter your %d element: ",i++);
		scanf("%d",&val);
		if(val != -1)
			(curr->data) = val;
		else
			break;
		prev->ptr = curr;
		curr->ptr = NULL;
		prev = prev->ptr;
	}
	return start;
}
void display(node *start)
{
	node *temp;
	temp = start;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
}
node *reversed(node *start, node *temp)
{
	node *curr = start;
	if(curr->ptr != NULL)
	{
		curr = start->ptr;
		start->ptr = temp;
//		if (temp !=NULL)
//			printf(" %d %d     ", start->data, temp->data);
//		else 
//				printf(" %d     ", start->data);
		return (reversed(curr, start));
	}
	else 
		start->ptr = temp;
		return start;
}
int main()
{
	printf("Welcome to  Link list...\n");
	node *start;
	start = create_list();
	display(start);
	printf("\n\n Reversed link list using recursion be: \n");
	node *prev = NULL;
	start = reversed(start, prev);
	display(start);
}
