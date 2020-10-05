#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *next, *back;
}node;
node *create(){
    node *root = NULL;
    int val;
    node *temp, *prev, *curr;
    printf("Enter your data till -1 is entered : \n");
    while(1)
    {
        scanf("%d",&val);
        if(val != -1)
        {
            if(root != NULL)
            {
                curr = (node *)malloc(sizeof(node));
                curr->data = val;
                curr->next = NULL;
                curr->back = prev;
                prev->next = curr;
                prev = curr;
            }
            else
            {
                root = (node *)malloc(sizeof(node));
                root->data = val;
                root->back = NULL;
                root->next = NULL;
                prev = root;
            }
        }
        else
            break;
    }
    if(root != NULL)
    {
        root->back = prev;
        prev->next = root;
    }
    return root;
}
void display(node *root)
{
    node *temp;
    temp = root;
    do{
        printf("%d\n",temp->data);
        temp = temp->next;
    }while(temp->back != root->back);
}
void reversal(node *root)
{
    node *temp, *prev;
    prev = root->back;
    temp = root;
    int x;
    do{
        x = temp->data;
        temp->data = prev->data;
        prev->data = x;
        temp = temp->next;
        prev = prev->back;
    }while(temp != prev && temp->back != prev);
}
int main()
{
    node *root;
    printf("Your link list is : \n");
    root = create();
    if(root == NULL)
        printf("Your link list is nullll \n");
    else
    {
        display(root);
        printf("Your reversed link list will be : \n");
        reversal(root);
        display(root);        
    }
    
}