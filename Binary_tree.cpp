#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *left;
    node *right;
}node;
node *create_bt(int , int );
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
int main()
{
    printf("\tWelcome to Binary treee program:\n");
    node *root;
    root = create_bt(0, 2);
    display_bt(root);
}
node *create_bt(int val, int index)
{
    node *root;
    root = (node *)malloc(sizeof(node));
    if(index == 1)
        printf("Enter value of child of %d of left side:", val);
    else if(index == 0)
        printf("Enter value of child of %d of right side:", val);
    else    
        printf("Enter value root element:");
    scanf("%d",&(root->data));
    printf("Whether child %d has left branch or not [y/n] :", val);
    char res;
    fflush(stdin);
    scanf("%c",&res);
    if(res == 'y' || res == 'Y')
        root->left = create_bt(root->data, 1);
    else
        root->left = NULL;
    printf("Whether child %d has right branch or not [y/n] :", val);
    fflush(stdin);
    scanf("%c",&res);
    if(res == 'y' || res == 'Y')
        root->right = create_bt(root->data, 0);
    else    
        root->right = NULL;
    return root;
}
