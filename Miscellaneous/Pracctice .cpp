// Recursive CPP program for level 
// order traversal of Binary Tree 
#include<stdio.h>
#include<stdlib.h> 
#include <bits/stdc++.h> 
using namespace std; 
typedef struct node  
{   
    int data;  
    node* left, *right;  
}node;  
void printGivenLevel(node* root, int level);  
int height(node* node);  
node* newNode(int data);  

void printLevelOrder(node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  

void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}
int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lheight = height(node->left);  
        int rheight = height(node->right);  
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  
node *create_bt(int val, int num)
{
    int value;
	node *root;
	root = (node *)malloc(sizeof(node));
	if(val == INT_MIN)
		printf("Enter root element : ");
	else if(val == 1)
		printf("Enter left child of %d : ", num);
	else
		printf("Enter right child of %d : ", num);
	scanf("%d",&value);
	if(value == -1)
		return NULL;
	else
	{
		root->data = value;
		root->left = create_bt(1, value);
		root->right = create_bt(0, value);
    }
    return root;
}
int main()  
{  
    node *root;
     root = create_bt(INT_MIN, 0);
    cout << "Level Order traversal of binary tree is \n";  
    printLevelOrder(root);  
  
    return 0;  
}  
  