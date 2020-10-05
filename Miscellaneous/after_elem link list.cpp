#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *ptr;
}node;

void display(node * start)
{
	node *temp;
	temp = start;
	while(temp->data != -1)
	{
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
}

node * create()
{
    node *curr, *prev;
    node *start;
    printf("Enter number till you enter -1:\n");
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
node * after_elem(node *start)
{
    int val;
    node *temp;
    printf("Enter value after which you want to insert value");
    scanf("%d",&val);
    temp = start;
    while(temp != NULL && temp->data != val)
    {
        temp = temp->ptr;
    }
    if(temp != NULL && temp->data == val)
    {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        printf("Enter your value");
        scanf("%d",&(newnode->data));
        newnode->ptr = temp->ptr;
        temp->ptr = newnode;
    }
    else
    {
        printf("\nValue doesn't exist......\n\n");
    }
    return start;
}
int main()
{
    node *start;
    printf("Welcome to link list org....");
    start = create();
    after_elem(start);
    display(start);
}