#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *ptr;
}node;
node *create()
{
	printf("Keep Entering Till -1 is entered : \n");
	node *root, *temp ,*curr;
	root = NULL;
	curr = root;
	temp = NULL;
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
		{
			curr = (node *)malloc(sizeof(node));
			curr->data = val;
			curr->ptr = NULL;
			if(root == NULL)
			{
				root = curr;
				temp = root;
			}
			else{
				temp->ptr = curr;
				temp = curr;
			}
		}
	}
	return root;
}
void split(node *root, node **one, node **two, node **three, node **four)
{
    node *temp, *prev, *curr;
    int i=1;
    while(temp != NULL)
    {
        curr = temp->ptr;
        if(i%4 == 1)
        {
            if(*one == NULL)
            {
                *one = temp;
                (*one)->ptr = NULL;
            }else
                prev = *one;
            
        }
        else if(i%4 ==2)
        {
            if(*two == NULL)
            {
                *two = temp;
                (*two)->ptr = NULL;
            }else
                prev = *two;
        }
        else if(i%4 ==3)
        {
            if(*three == NULL)
            {
                *three = temp;
                (*three)->ptr = NULL;
            }else
                prev = *three;
        }
        else
        {
            if(*four == NULL)
            {
                *four = temp;
                (*four)->ptr = NULL;
            }else
                prev = *four;           
        }
        while(prev->ptr != NULL)
            prev = prev->ptr;
        prev->ptr = temp;
        temp->ptr = NULL;
        temp = curr;
    }
}
int main()
{
    node *root;
    root = create();
    node *one, *two, *three, *four;
    split(root, &one, &two, &three, &four);
}