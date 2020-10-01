#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *ptr;
}node;
void create(node *front, node *last)
{
	printf("Enter your number, keep entering till -1 is not entered");
	node *curr, *temp, *prev;
	int val;
	curr = (node *)malloc(sizeof(node));
	front = curr;
	scanf("%d",&(curr->data));
	temp = curr;
	while(1)
	{
		scanf("%d",&val);
		if(val != -1)
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->ptr = NULL;
			temp->ptr = curr;
			temp = curr;
		}
		else
			break;
		printf(" ** %u %d %u %d ** \n",temp->ptr, temp->data, curr->ptr, curr->data);
	}
	last = curr;
}
void display(node *);
int main()
{
    printf("\t\t<<<<<<<================================Welcome to world of link list and queues====================================>>>>>>>>\n");
    int ans;
    node *front, *last;
    while(1)
    {
        printf("Enter your choices:\n");
        printf("1. Create a queue\n");
        printf("2. Insert element to queue\n");
        printf("3. Remove an element from queue\n");
        printf("4. Display all elements of queue\n");
        printf("5. Exit\n");
        scanf("%d",&ans);
        if(ans == 5)
            break;
        switch(ans)
        {
            case 1:create(front, last);break;
            case 2:break;
            case 3:break;
            case 4:display(front);break;
            default: printf("Wrong input\n");break;
        }
    }
    display(front);
}
void display(node *start)
{
    node *temp;
    temp = start;
    printf("%d %d",start->ptr, start->data);
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->ptr;
    }
}
