#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int data;
	node *left, *right;
}node;
void function();
node*create();
void display(node *);
node* recursive();
node* nonrecursive();
node * insert(node *, int);
void in(node *);
void pre(node *);
void post(node *);
node * Search(node *, int);
int main()
{
	printf(" \t\t <<<< Welcome to Binary Search Tree >>>>\n ");
	function();
	printf(" \t\t <<<< Thanks for using binary search tree function >>>> \n");
}
void function()
{
	int ans;
	node *root = NULL;
	while(1)
	{
		printf("Enter your choice : \n");
		printf("1. Create \n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Exit\n");
		scanf("%d",&ans);
		if(ans == 4)
			break;
		switch(ans)
		{
			case 1: root = create(); break;
			case 2: display(root);break;
			case 3: int val;
					printf("Enter value to be searched...\n");
					scanf("%d",&val);
					node *tempo;
					tempo = Search(root, val);
					printf("%d",tempo->data);
					printf("\n%u\n", tempo);
		}
	}
}
node *create()
{
	node *root;
	root = NULL;
	printf("Enter your choice : \n");
	printf("1. Recursive \n");
	printf("2. Non-Recursive \n");
	int ans;
	scanf("%d",&ans);
	switch(ans)
	{
		case 1: root = recursive();break;
		case 2: root = nonrecursive();break;
	}
	return root;
}
node * recursive()
{
	int val;
	node *root;
	root = NULL;
	printf("Keep Entering Value till -1 is entered \n");
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
			root = insert(root, val);
	}
	return root;
}
node * insert(node *root, int val)
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if(val < root->data)
		{
			if(root->left != NULL)
				insert(root->left, val);
			else
			{
				node *newn;
				newn = (node *)malloc(sizeof(node));
				newn->data = val;
				newn->left = NULL;
				newn->right = NULL;
				root->left = newn;
			}
		}
		else if(val > root->data)
		{
			if(root->right != NULL)
				insert(root->right, val);
			else
			{
				node *newn;
				newn = (node *)malloc(sizeof(node));
				newn->data = val;
				newn->left = NULL;
				newn->right = NULL;
				root->right = newn;
			}
		}
		else
			printf("Unique Value Please ......\n");
	}
	return root;
}
node * nonrecursive()
{
	node *root = NULL;
	node *temp = NULL;
	printf("Keep Entering Data till -1 is input.....\n");
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
		{
			temp = root;
			while(1)
			{
				if(temp != NULL)
				{
					if(val < temp->data)
					{
						if(temp->left == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->left = newn;
							break;
						}
						else
							temp = temp->left;
					}
					else if(val > temp->data)
					{
						if(temp->right == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->right = newn;
							break;
						}	
						else
							temp = temp->right;
					}
					else
					{
						printf("\t\tUnique Number Please...... \n");
						break;
					}
				}
				else
				{
					root = (node *)malloc(sizeof(node));	
					root->data = val;
					root->left = NULL;
					root->right = NULL;
					break;
				}
			}
		}
	}
	return root;
}
void display(node *root)
{
	printf("Enter your choice : \n");
	printf("1. In-order Treaversal\n");
	printf("2. Pre-Oreder Traversal\n");
	printf("3. Post-Order Traversal\n");	
	int ans;
	scanf("%d",&ans);
	switch(ans)
	{
		case 2: pre(root); break;
		case 3: post(root);break;
		default : in(root);break;
	}
}
void in(node *root)
{
	if(root != NULL)
	{
		in(root->left);
		printf("%d\n",root->data);
		in(root->right);
	}
}
void post(node *root)
{
	if(root != NULL)
	{
		post(root->left);
		post(root->right);
		printf("%d\n",root->data);
	}
}
void pre(node *root)
{
	if(root != NULL)
	{
		printf("%d\n",root->data);
		pre(root->left);
		pre(root->right);
	}
}
node * Search(node *root, int val)
{
	if(root != NULL)
	{
		if(root->data == val)
			return root;
		else if(val < root->data)
			return Search(root->left , val);
		else
			return Search(root->right , val);
	}
	else 
		return NULL;
}
