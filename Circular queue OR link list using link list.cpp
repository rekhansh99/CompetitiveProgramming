#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int data;
    node *ptr;
}node;
int main()
{
    printf("\t\t<<<<<============== WELCOME TO CIRCULAR LIST ================>>>>>\n");
    function();
}
void function()
{
    int ans;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Traverse list and display\n");z
		printf("4. Exit and display list\n");
		scanf("%d",&ans);
		if(ans == 4)
			break;
		switch(ans)
		{
			case 1:	start = insert_eleme(start);break;
			case 2:	start = delete_eleme(start);break;
			case 3:	traverse_displ(start);break;
		}
	}
	display(start);
}
node * delete_eleme(node *start)
{
	int ans;
	printf("Enter your choice:\n");
	printf("1. Deleting a specific position\n");
	printf("2. Deleting after an element\n");
	printf("3. Deleting before an element\n");
	printf("4. Deleting an element\n");
	scanf("%d",&ans);
	switch(ans)
	{
		case 1:start = delete_pos(start) ;break;
		case 2:delete_after(start);break;
		case 3:start = delete_before(start) ;break;
		case 4:start = delete_elem(start); break;	
	}	
	return start;
}
node * insert_eleme(node *start)
{
	int ans;
	printf("Enter your choice :\n");
	printf("1. Insert at specific position\n");
	printf("2. Insert after element\n");
	printf("3. Insert before element\n");
	printf("4. Insert at place of element");
	scanf("%d",&ans);
	switch(ans)
	{
		case 1:start = insert_pos(start) ;break;
		case 2:start = insert_after(start) ;break;
		case 3:start = insert_before(start) ;break;
		case 4:start = overwrite(start) ;break;
	}
	return start;
}
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
