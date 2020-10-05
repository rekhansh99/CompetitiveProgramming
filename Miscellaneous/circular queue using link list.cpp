#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct node{
	int data;
	node *ptr;
}node;
void display(node **start, node **endd)
{
	if(*start != NULL)
	{
		node *temp;
		temp = *start;
		printf("Here comes your queue....\n");
		while(temp != *endd)
		{
			printf("%d\n",temp->data);
			temp = temp->ptr;
		}
		if(*endd != NULL)
		printf("%d\n",(*endd)->data);
	}
}
void delete_q(node **start, node**endd)
{
	if(*start != NULL)
	{
		node *temp;
		temp = (*start)->ptr;
		free(*start);
		*start = temp;
		(*endd)->ptr = *start;
	}
}
void create(node **start, node **endd)
{
	*start = (node *)malloc(sizeof(node));
	scanf("%d",&((*start)->data));
	int val;
	node *curr, *temp;
	temp = *start;
	*endd = *start;
	while(1)
	{
		scanf("%d",&val);
		if(val != -1)
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->ptr = *start;
			temp->ptr = curr;
			temp = curr;
			*endd = curr;
		}
		else
			break;
	}
}
void add(node **start, node **endd)
{
	node *newn;
	newn = (node *)malloc(sizeof(node));
	printf("Enter your data : ");
	scanf("%d",&(newn->data));
	(*endd)->ptr = newn;
	newn->ptr = *start;	
	*endd = newn;
}
void function()
{
	int val;
	printf("Enter your choice :\n");
	printf("1. Create\n");
	node *start, *endd;
	start = NULL;
	endd = NULL;
	scanf("%d",&val);
	create(&start, &endd);
	while(1)
	{
		printf("Enter your choice : \n");
		printf("1. Create\n");
		printf("2. Remove\n");
		printf("3. Display\n");
		printf("4. Add to Queue\n");
		printf("5. Exit\n");
		scanf("%d",&val);
		if(val == 5)
			break;
		else
		{
			switch(val)
			{
				case 1: create(&start, &endd);break;
				case 2: delete_q(&start, &endd);break;
				case 3: display(&start, &endd);break;
				case 4: add(&start, &endd); break;
			}
		}
	}
}
int main()
{
	printf(" << Welcome to Circular link list >> \n");
	function();
	printf(" << Thanks for using Circular link list >> \n");
}