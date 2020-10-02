#include <stdio.h>
#define max 50

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

node *createTree(int val, int dir)
{
	int data;
	node *root = (node *)malloc(sizeof(node));
	if (val != -1)
	{
		if (dir)
			printf("Enter left child of %d\n", val);
		else
			printf("Enter right child of %d\n", val);
	}
	scanf("%d", &data);
	root->data = data;
	int choice;
	printf("Does %d has a left child?\nEnter 1 for yes and 0 for no\n", root->data);
	scanf("%d", &choice);
	if (choice)
		root->left = createTree(root->data, 1);
	else
		root->left = NULL;

	printf("Does %d has a right child?\nEnter 1 for yes and 0 for no\n", root->data);
	scanf("%d", &choice);
	if (choice)
		root->right = createTree(root->data, 0);
	else
		root->right = NULL;

	return root;
}

void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

void insert(node *stack[], node *data, int *rear)
{
	if (*rear < max - 1)
		stack[(*rear)++] = data;
}

node *del(node *stack[], int *front, int rear)
{
	if (*front <= rear)
		return stack[(*front)++];
	else
		return NULL;
}

void levelOrderTraversal(node *root)
{
	puts("Level Order Traversal:");
	node *stack[max];
	int front = 0, rear = 0;
	int levels[max], i;
	for (i = 0; i < max; i++)
		levels[i] = 0;

	insert(stack, root, &rear);

	node *temp;
	temp = del(stack, &front, rear);

	int t1 = 1;
	int t2 = 0;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		t1--;
		if (temp->left != NULL)
		{
			insert(stack, temp->left, &rear);
			t2++;
		}

		if (temp->right != NULL)
		{
			insert(stack, temp->right, &rear);
			t2++;
		}

		temp = del(stack, &front, rear);

		if (t1 == 0)
		{
			printf("\n");
			t1 = t2;
			t2 = 0;
		}
	}
}

int main()
{
	node *root;
	root = createTree(-1, 0);
	puts("InOrder Traversal:");
	inorder(root);
	levelOrderTraversal(root);
	return 0;
}
