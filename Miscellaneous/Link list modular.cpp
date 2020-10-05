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
	printf("Enter your %d element: ", i++);
	scanf("%d",&(start->data));
	prev = start;
	while(prev->data != -1)
	{
		curr = (node *)malloc(sizeof(node));
		printf("Enter your %d element: ",i++);
		scanf("%d",&(curr->data));
		prev->ptr = curr;
		prev = prev->ptr;
	}
	return start;
}
void display(node *start)
{
	node *temp;
	temp = start;
	while(temp -> data != -1)
	{
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
}
int main()
{
	printf("Welcome to  Link list...\n");
	node *start;
	start = create_list();
	display(start);
}
