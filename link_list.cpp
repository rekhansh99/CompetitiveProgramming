#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
int main()
{
	printf("Enter number in list and enter -1 for exiting .......\n");
	node *start = (node *)malloc(sizeof(node));
	node *prev;
	node *cur;
	int i=1, elem;
	printf("Enter your data now!!\n");
	printf("Enter your %d element : ",i++);
	scanf("%d",&(*start).data);
	prev = start;
	while(prev->data != -1)
	{
		cur = (node *)malloc(sizeof(node));
		printf("Enter your %d element : ",i++);
		scanf("%d",&elem);
		cur -> data = elem;
		prev->ptr = cur;
		prev = cur;		
	}
	prev->ptr = NULL;
	node *temp;
	temp = start;
	printf("Your link list ....\n");
	i = 0;
	while(temp->data != -1)
	{
		i++;
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
	if( i == 0)
		printf("\nSorry !! Your link list is null");
}
