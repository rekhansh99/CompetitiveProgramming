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
		curr->next = NULL;
		prev = curr;
	}
	return start;
}
void display(node *start)
{
	node *temp;
	temp = start;
	while(temp->next != NULL)
	{
		if(temp->data != -1)
			printf("%d\n",temp->data);
		temp = temp->next;
	}
}
node * reversal(node *start)
{
	node *temp, *curr, *prev;
	temp = start;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	start = (node *)malloc(sizeof(node));
	node *newn;
	newn = start;
	prev = start;
	while(temp != NULL)
	{
		prev->data = temp->data;
		temp = temp->back;
		curr = (node *)malloc(sizeof(node));
		curr->back = prev;
		prev->next = curr;
		prev = curr;
	}
	return newn;
}
int main()
{
	printf("\t\t<<<<<======================Welcome to Doubly link list coorp....======================>>>>>\n");
	node *start = create();
	printf("SO, here comes your doubly link list......\n");
	display(start);
	printf("SO, here comes your reversed doubly link list......\n");
	start = reversal(start);
	display(start);
	printf("\t\t<<<<<<=====Thank you for using us.... ======>>>>>>>\n");
}
