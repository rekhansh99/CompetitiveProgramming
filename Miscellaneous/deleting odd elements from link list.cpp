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
void display(node *root){
	if(root != NULL)
	{
		printf("%d \n",root->data);
		display(root->ptr);
	}
}
node *delete_node(node *root)
{
    node *curr, *temp;
    if(root != NULL  && root->ptr != NULL && root->ptr->ptr != NULL)
    {
         temp = root;
         curr = temp->ptr;
         free(temp);
         curr->ptr = delete_node(curr->ptr);
         return curr;
    }
    else if(root != NULL && root->ptr != NULL)
    {
        temp = root;
        curr = temp->ptr;
        free(temp);
        return curr;
    }
    return NULL; 
}

int main()
{
    node *root;
    root = create();
    display(root);
    root = delete_node(root);
    printf("\nSo, here is your remaining link list: \n");
    if(root == NULL)
        printf("Link list is empty....\n");
    else    
        display(root);
}