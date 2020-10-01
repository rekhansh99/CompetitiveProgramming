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
int pop(int stack[], int *top)
{
	if(top >= 0)
		return(stack[(*top)--]);
}
void push(int stack[], int *top, int data)
{
	stack[++(*top)] = data;
}
node *reversal(node *start)
{
	node *temp, *curr, *prev;
	int stack[1000];
	int top = -1;
	temp = start;
	while(temp != NULL && temp->data != -1)
	{
		push(stack, &top, temp->data);
		prev = temp;
		temp = temp->ptr;
		free(prev);
	}
	while(top >= 0)
	{
		printf("%d ",(pop(stack, &top)));
	}
	start = (node *)malloc(sizeof(node));
	start->data = pop(stack, &top);
	prev = start;
	temp = start;
	while(top >= 0)
	{
		curr = (node *)malloc(sizeof(node));
		curr->data = pop(stack, &top);
		prev->ptr = curr;
		prev = curr;
	}
	return temp;
}
int main()
{
	printf("Welcome to  Link list...\n");
	node *start;
	start = create_list();
    printf("So, here comes you list:\n");
    display(start);
    start = reversal(start);
    printf("So, here is your reversed list:\n");
    display(start);
}
