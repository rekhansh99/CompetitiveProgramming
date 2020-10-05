#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *back;
	node *next;
}node;
node *create()
{
	printf("Keep entering till -1 is not entered");
	printf("Enter your data:\n");
	node *start, *temp, *curr;
	temp = start;
	scanf("%d",&(start->data));
	start->back = NULL;
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val != -1)
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->back = temp;
			temp->next = curr;
			curr->next = NULL;
			temp = curr; 
		}
		else	
			break;
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
		temp = temp->next;
	}
}
node *insert_pos(node *start)
{
	node *temp, *curr;
	int val;
	printf("Enter place to enter the value:");
	scanf("%d",&val);
	temp = start;
	if(val == 1)
	{
		node *new_node;
		new_node = (node *)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d",&(new_node->data));
		new_node->next = start;
		new_node->back = NULL;
		return new_node;
	}
	else
	{
		node *prev;
		while(temp != NULL && val > 1)
		{
			prev = temp;
			temp = temp->next;
			val--;
		}
		if(temp != NULL)
		{
			curr = (node *)malloc(sizeof(node));
			printf("Enter your value");
			scanf("%d",&(curr->data));
			curr->next = temp;
			curr->back = temp->back;
			(temp->back)->next = curr;
			temp->back = curr;
			
		}
		else if (temp == NULL && val == 0){
			curr = (node *)malloc(sizeof(node));
			printf("Enter your value");
			scanf("%d",&(curr->data));
			prev->next = curr;
			curr->back = prev;
			curr->next = NULL;			
		}
		else
			printf("\nNo such index is found....\n\n");
	}
	return start;
}
node *insert_after(node *start)
{
	node *temp, *curr;
	printf("Enter the value after whcih you want to enter data:");
	int val;
	scanf("%d",&val);
	temp = start;
	while(temp != NULL && temp->data != val)
	{
		temp = temp->next;
	}
	if(temp != NULL && temp->data == val)
	{
		curr = (node *)malloc(sizeof(node));
		printf("Enter your value to be entered:");
		scanf("%d",&(curr->data));
		curr->next = temp->next;
		curr->back = temp;
		temp->next = curr;
		temp->next->back = curr;
	}
	else
		printf("\nNo such element is found....\n\n");	
	return start;
}
node *insert_before(node *start)
{
	int val;
	node *temp, *curr;
	printf("Enter value before you want to enter your value:");
	scanf("%d",&val);
	temp = start;
	if(start->data == val)
	{
		node *curr;
		curr = (node *)malloc(sizeof(node));
		printf("Enter your value to be entered:");
		scanf("%d",&(curr->data));
		curr->back = NULL;
		curr->next = start;
		start->back = curr;
		return curr;
	}
	else
	{
		while(temp != NULL && temp->data != val)
		{
			temp = temp->next;
		}
		if(temp != NULL && temp->data == val)
		{
			curr = (node *)malloc(sizeof(node)); 
			printf("Enter your value to be entered:");
			scanf("%d",&(curr->data));
			temp = temp->back;
			curr->next = temp->next;
			curr->back = temp;
			temp->next = curr;
			curr->next->back = curr;			
		}
		else
			printf("No such element is found.....\n");
		return start;
	}
	
	
}
void overwrite(node *start)
{
	int val;
	printf("ENter element to be overwritten:");
	scanf("%d",&val);
	node *temp;
	temp = start;
	while(temp != NULL && temp->data != val)
	{
		temp = temp->next;
	}
	printf("Enter your value :");
	scanf("%d",&(temp->data));
}
node *delete_pos(node*start)
{
	int val;
	printf("Enter your value for postition:");
	scanf("%d",&val);
	node *temp; 
	temp = start;
	if(val == 1)
	{
		temp = start->next;
		temp->back = NULL;
		free(start);
		return temp;
	}
	else
	{
		while(temp != NULL && val > 1)
		{
			temp = temp->next;
			val--;
		}
		if(temp->next != NULL)
		{
			temp->back->next = temp->next;
			temp->next->back = temp->back;
			free(temp);
		}			
		else if(temp->next == NULL)
		{
			temp->back->next = NULL;
			free(temp);
		}
		else
			printf("No such index exist.....\n");
		return start;
	}
	
}
node *delete_elem(node *start)
{
	int val;
	printf("Enter value you want to delete :");
	scanf("%d",&val);
	node *temp;
	temp = start;
	if(start->data == val)
	{
		temp = start->next;
		temp->back = NULL;
		free(start);
		return temp;
	}
	else
	{
		while(temp != NULL && temp->data != val)
		{
			temp = temp->next;
		}
		if(temp->next == NULL && temp->data == val)
		{
			temp->back->next = NULL;
			free(temp);
		}
		else if(temp != NULL && temp->data == val)
		{
			temp->back->next = temp->next;
			temp->next->back = temp->back;
			free(temp);
		}
		else 
			printf("No such number exist....\n");
		return start;
	}
}
node *delete_before(node *start)
{
	int val;
	printf("Enter value before which you want to delete data:");
	scanf("%d",&val);
	node *temp, *curr, *prev;
	if(start->data == val)
		printf("Not a valid index....\n");
	else if(start->next->data == val)
	{
		curr = start->next;
		curr->back = NULL;
		free(start);
		return (curr);
	}
	else
	{
		temp = start;
		while(temp != NULL && temp->data!= val)
		{
			temp = temp->next;
		}
		if(temp != NULL && temp->data == val)
		{
			temp = temp->back->back;
			temp->back->next = temp->next;
			temp->next->back = temp->back;
		}
		else	
			printf("No, such postiton....\n");
	}
	return start;
	
}
void delete_after(node *start)
{
	node *temp, *curr;
	int val;
	printf("Enter your value after which element to be deleted:");
	scanf("%d",&val);
	temp = start;
	while(temp->next != NULL && temp->data != val)
	{
		temp = temp->next;
	}
	temp = temp->next;
	if(temp->next == NULL && temp->data == val)
	{
		temp->back->next = NULL;
		free(temp);
	}
	else if(temp->next != NULL && temp->data == val && temp != NULL)
	{
		temp->back->next = temp->next;
		temp->next->back = temp->back;
		free(temp);
	}
	else
		printf("No such element found....\n");
} 
node *insert_eleme(node *start)
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
		case 4:overwrite(start) ;break;
	}
	return start;
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
	temp = start;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	printf("So ,Here goes your reverse doubly link list.....\n");
	while(temp != NULL)
	{
		printf(" %d \n",(temp->data));
		temp = temp->back;
	}
}
void function(node *start)
{
	int ans;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Display\n");
		printf("4. Traverse list  from backward and display\n");
		printf("5. Exit and display list\n");
		scanf("%d",&ans);
		if(ans == 5)
			break;
		switch(ans)
		{
			case 1:	start = insert_eleme(start);break;
			case 2:	start = delete_eleme(start);break;
			case 3: display(start); break;
			case 4:	traverse_displ(start);break;
		}
	}
	display(start);
}
int main()
{
	printf("\t\t<<<<<======================Welcome to Doubly link list coorp....======================>>>>>\n");
	node *start = create();
	function(start);
	printf("\t\t<<<<<<=====Thank you for using us.... ======>>>>>>>\n");
}
