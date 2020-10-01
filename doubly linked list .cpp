#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *back;
	node *next;
}node;
node *create()
{
	node *start;
	node *curr, *prev;
	start = (node *)malloc(sizeof(node));
	printf("Enter your value , till -1 is entered\n");
	scanf("%d",&(start->data));
	start->back = NULL;
	prev = start;
	while(prev->data != -1)
	{
		curr = (node *)malloc(sizeof(node));
		scanf("%d",&(curr->data));
		prev->next = curr;
		curr->back = prev;
		prev = curr;
	}
	return start;
}
void display(node *start)
{
	printf("SO, here comes your doubly link list......\n");
	node *temp;
	temp = start;
	while(temp->data != -1)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}
int main()
{
	printf("\t\t<<<<<======================Welcome to Doubly link list coorp....======================>>>>>\n");
	node *start = create();
	display(start);
	
}
