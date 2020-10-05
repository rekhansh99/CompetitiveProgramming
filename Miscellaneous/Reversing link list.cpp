#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
node * reverse_list(node *);
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
        prev->ptr = NULL;
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
node * reverse_list(node *start)
{
    node *temp, *curr, *prev;
    prev = NULL;
    temp = start;
    curr = start->ptr;
    while(temp->ptr != NULL && temp->data != -1)
    {
        temp->ptr = prev;
        prev = temp;
        temp = curr;
        if(curr->ptr != NULL)
           curr = curr->ptr;
        else
           break;
    }
    temp->ptr = prev;
    return prev;
}
int main()
{
	printf("Welcome to  Link list...\n");
	node *start;
	start = create_list();
    printf("So, here comes you list:\n");
    display(start);
    start = reverse_list(start);
    printf("So, here is your reversed list:\n");
    display(start);
}
