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
	printf("SO, here comes your doubly link list......\n");
	node *temp;
	temp = start;
	while(temp != NULL)
	{
		if(temp->data != -1)
			printf("%d\n",temp->data);
		temp = temp->back;
	}
}
node *reversal(node *start)
{
	node *prev, *temp, *curr, *ptr;
	prev = start;
	temp = start->next;
	curr = temp->next;
	while(curr != NULL)
	{
		temp->back = prev;
		prev->next = temp;
		prev = temp;
		temp = curr;
		curr = curr->next;
	}
	return temp;
}
int main()
{
	printf("\t\t<<<<<======================Welcome to Doubly link list coorp....======================>>>>>\n");
	node *start = create();
	display(start);
	start = reversal(start);
	// start = start->next;
	display(start);
	printf("\t\t<<<<<<=====Thank you for using us.... ======>>>>>>>\n");
}
