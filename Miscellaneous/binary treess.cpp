#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *left;
    node *right;
}node;
void create_bt(node *,  int);
void display_bt(node *);
int main()
{
    printf("\t\t<<<Welcome to world of bianry trees.... >>>\n");
    node *root;
    printf("Enter your data and enter -1 to exit the program.....\n");
    printf("Enter root element:");
    root = (node *)malloc(sizeof(node));
    create_bt(root, 0);
    display_bt(root);
    printf("\t\t <<< Thanx for using bianry tree function >>>\n");
}
void create_bt(node *root, int val)
{
    scanf("%d",&(root->data));
    if(root->data != -1)
    {
        node *newn;
        newn = (node *)malloc(sizeof(node));
        root->left = newn;
        printf("Enter your left child of %d :", root->data);
        create_bt(newn, root->data);
        newn = (node *)malloc(sizeof(node));
        root->right = newn;
        printf("Enter your right child of %d :", root->data);
        create_bt(newn, root->data);
    }
    return;   
}
void display_bt(node *root)
{
    if(root != NULL)
    {
        display_bt(root->left);
        printf("%d ",root->data);
        display_bt(root->right);
        printf("\n");
    }
}
