#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *back, *front;
}node;
void display(node *start)
{
	node *temp;
	temp = start;
	printf(" <<< This is your link list >>>> \n");
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->front;
	}
}
node *create()
{
	node *start, *temp, *curr;
	start = (node *)malloc(sizeof(node));
	scanf("%d",&start->data);
	int val;
	start->back = NULL;
	start->front = NULL;
	temp = start;
	while(1)
	{
		scanf("%d",&val);		
		if(val == -1)
			break;
		else
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->front = NULL;
			curr->back = temp;
			temp->front = curr;
			temp = curr;
		}
	}
	display(start);
}
node *insert(node *start)
{
	int pos;
	int val;
	printf("Enter your position for entering your data: ");
	scanf("%d",&pos);
	
}
int main()
{
	node *start;
	start = create();
}
