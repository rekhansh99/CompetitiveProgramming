#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
void display(node *start)
{
	printf("So here is your link list!! ......\n");
	node *temp;
	temp = start;
	while(temp != NULL && temp->data != -1)
	{
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
}
node *create()
{
	node *start;
	node *curr;
	node *temp;
	node *prev;
	printf("Input -1 to exit entering.....\nEnter data:\n");
	int i=1;
	start = (node *)malloc(sizeof(node));
	scanf("%d",&(start->data));
	prev = start;
	while(prev->data != -1)
	{
		curr = (node *)malloc(sizeof(node));
		scanf("%d",&(curr->data));
		prev->ptr = curr;
		prev = curr;
	}
	return start;
}
void del_after(node *start)
{
	
}
int mai()
{
	node *start;
	start = create();
	del_after(start);
	display(start);
}
