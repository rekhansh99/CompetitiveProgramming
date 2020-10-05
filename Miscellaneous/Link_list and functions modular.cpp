#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *ptr;
}node;
void display(node *);
node *insert_pos(node *start)
{
	printf("Enter your position at which you want to enter data:");
	int val;
	scanf("%d",&val);
	node *temp, *prev;
	temp = start;
	prev = start;
	if(val == 1)
	{
		node *newnode;
		newnode = (node *)malloc(sizeof(node));
		printf("Enter your value:");
		scanf("%d",&(newnode->data));
		newnode->ptr = start;
		return newnode;
	}
	while(temp->ptr != NULL && val-1 > 0)
	{
		prev = temp;
		temp = temp->ptr;
		val--;
	}
	if(val == 0 && temp != NULL)
	{
		node *newnode;
		printf("Enter your value:");
		scanf("%d",&(newnode->data));
		if(temp->ptr == NULL)
			newnode->ptr = NULL;
		else
			newnode->ptr = temp->ptr;
		prev->ptr = newnode;
	}
	else
		printf("\nNo such element found.....\n\n");
	return (start);
}
node * insert_after(node * start)
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
node * insert_before(node * start)
{
	int before, val;
	printf("Enter value before which you want to place value:");
	scanf("%d",&before);
	printf("Enter value which you want to enter:");
	scanf("%d",&val);
	node *temp, *prev, *newnode;
	prev = start;
	if(temp != NULL || prev->data == before)
	{
		newnode = (node *)malloc(sizeof(node));
		newnode->data = val;
		newnode->ptr = start;
		return newnode;
	}
	else
	{
		while(temp != NULL && temp->data != before)
		{
			prev = temp;
			temp = temp->ptr;
		}
		if(prev->data != before)
			printf("Sorry !! No such element exist");
		else
		{
			newnode = (node *)malloc(sizeof(node));
			newnode->data = val;
			newnode->ptr = temp;
			prev->ptr = newnode;
		}
		return start;
	}
	
}
node * overwrite(node *start)
{
	int at, val;
	printf("Insert value to be overwritten and with which value:");
	scanf("%d %d",&at, &val);
	node *temp;
	node *prev;
	prev = start;
	while(prev != NULL && prev->data != at)
	{
		prev = prev->ptr;
	}
	if(temp == NULL || prev->data!= at)
		printf("No such element exist\n");
	else
		prev->data = val;
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
node * delete_pos(node *start)
{
	int pos;
	node *temp, *prev;
	printf("Enter the position at which you want to delete element:");
	scanf("%d",&pos);
	if(pos == 1)
	{
		prev = start->ptr;
		free(start);
		return prev;
	}
	else
	{
		temp = start;
		while(temp != NULL && pos > 1)
		{
			prev = temp;
			temp = temp->ptr;
			pos--;
		}
		if(temp == NULL || pos != 1)
			printf("This postition doesn't exist.....\n");
		else
		{
			prev->ptr = temp->ptr;
			free(temp);
		}	
	}
	return start;
}
void delete_after(node *start)
{
	node *temp;
	int daata;
	printf("Enter your data after which data to be deleted:");
	scanf("%d",&daata);
	temp = start;
	node *prev;
	while(temp != NULL && temp->data != daata)
	{
		if(temp->ptr == NULL)
			break;
		temp = temp->ptr;
	}	
	if(temp->ptr != NULL)
	{
		prev = temp->ptr;
		temp->ptr = prev->ptr;
		free(prev);
	}
	else	
		printf("No element exist .......\n");
}
node * delete_before(node *start)
{ 
	int val;
	printf("Enter value before the  numebr is to be deleted:");
	scanf("%d",&val);
	node *temp, *prev;
	if(val == start->data)
		printf("Sorry !! invalid input...\n");
	else
	{
		temp = start;
		if(temp->ptr->data == val)
		{
			temp = temp->ptr;
			free(start);
			return temp;
		}
		while(temp != NULL && temp->data != val)
		{
			prev = temp;
			temp = temp->ptr;
		}
		if(temp->data == val)
		{
			prev->ptr = temp->ptr;
			free(temp);
		}
		else
		{
			printf("No, such element exist......\n");
		}	
	}
	return start;
}
node * delete_elem(node *start)
{
	int num;
	printf("Enter the element you want to delete");
	scanf("%d",&num);
	node *temp, *prev;
	temp = start;
	if(start->data == num)
	{
		temp = start->ptr;
		free(start);
		return temp; 
	}
	else
	{
		while(temp != NULL && temp->data != num)
		{
			prev = temp;
			temp = temp->ptr;
		}
		if(temp == NULL)
			printf("No such element....\n");
		else
		{
			prev = temp->ptr;
			free(temp);
		}
		return start;
	}
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
void traverse_displ(node *start)
{
	node *temp;
	int num;
	printf("Enter number by which you want to traverse list and then display:");
	scanf("%d",&num);
	temp = start;
	while(num>0 && (temp->ptr != NULL))
	{
		temp = temp->ptr;
		num--;
	}
	if(num > 0)
		printf("Sorry link list could not be printed.....\n");
	else
	{
		display(temp);
	}
}
void display(node *start)
{
	printf("So here is your link list!! ......\n");
	node *temp;
	temp = start;
	while(temp != NULL && temp->data != -1)
	{
		printf("%d\n",temp->data);
		temp = temp->ptr;
	}
}
node *create()
{
	node *start;
	node *curr;
	node *prev;
	printf("Input -1 to exit entering.....\nEnter data:\n");
	start = (node *)malloc(sizeof(node));
	scanf("%d",&(start->data));
	prev = start;
	while(prev->data != -1)
	{
		curr = (node *)malloc(sizeof(node));
		scanf("%d",&(curr->data));
		prev->ptr = curr;
		prev = prev->ptr;
	}
	return start;
}
void function(node *start)
{
	int ans;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Traverse list and display\n");
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
int main()
{
	printf("======================================>>--<<Welcome to Link list Corporation>>--<<====================================== \n");
	node *start;
	start = create();
	function(start);
	printf("====================================<<< Thanks for using link linst coorporation >>>====================================\n\n\n");
}
