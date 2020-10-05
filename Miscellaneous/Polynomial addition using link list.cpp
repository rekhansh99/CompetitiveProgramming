#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data, exp;
    node *ptr;
} node;
node *create();
void display(node *);
node * poly_add(node *, node *);
int main()
{
    printf("\t<<<<<======================= Welcome to Polynomial addition using link list =======================>>>>>\n\n");
    node *poly1;
    node *poly2;
    printf("Enter your first polynomial:\n");
    poly1 = create();
    printf("Enter your second polynomia:\n");
    poly2 = create();
    printf("So your polnomial first is:\n");
    display(poly1);
    printf("So your polnomial second is:\n");
    display(poly2);
    node *poly3;
    poly3 = poly_add(poly1, poly2);
    printf("So your final polynomial due to sum is......\n");
    display(poly3);
}
node *create()
{
    printf("\nEnter -1 and -1 to exit entering data...\n");
    printf("Enter Your polynomial :\n");
    printf("Data\tExp\n");
    int val, index;
    node *start;
    node *temp;
    node *curr;
    start = NULL;
    while (1)
    {
        scanf("%d %d", &val, &index);
        if (index != -1 && val != -1)
        {
            temp = (node *)malloc(sizeof(node));
            if (start == NULL)
            {
                start = (node *)malloc(sizeof(node));
                start->data = val;
                start->exp = index;
                start->ptr = NULL;
                curr = start;
            }
            else
            {
                temp->data = val;
                temp->exp = index;
                curr->ptr = temp;
                temp->ptr = NULL;
                curr = temp;
            }
        }
        else
            break;
    }
    curr->ptr = NULL;
    return start;
}
void display(node *start)
{
    node *temp;
    temp = start;
    while (temp->ptr != NULL)
    {
        printf(" %d*(X^%d) ", (temp->data), (temp->exp));
        temp = temp->ptr;
        if(temp->data >0)
            printf("+");
    }
    printf(" %d*(X^%d) ", (temp->data), (temp->exp));
    printf("\n");
}
node *poly_add(node *poly1, node *poly2)
{
    node *start, *temp, *curr;
    start = (node *)malloc(sizeof(node));
    temp = start;
    while(poly1 != NULL && poly2 != NULL)
    {
        if(poly1->exp > poly2->exp)
        {
            temp->exp = poly1->exp;
            temp->data = poly1->data;
            poly1 = poly1->ptr;
        }
        else if(poly1->exp < poly2->exp)
        {
            temp->exp = poly2->exp;
            temp->data = poly2->data;   
            poly2 = poly2->ptr;
        }
        else
        {
            temp->exp = poly1->exp;
            temp->data = poly1->data + poly2->data;
            poly1 = poly1->ptr;
            poly2 = poly2->ptr;
        }
        curr = (node *)malloc(sizeof(node));
        temp->ptr = curr;
        temp = curr;
    }
    while(poly1 != NULL)
    {
        temp->data = poly1->data;
        temp->exp = poly1->exp;
        curr = (node *)malloc(sizeof(node)); 
        temp->ptr = curr;
        temp = curr;
        poly1 = poly1->ptr;
    }
    while(poly2 != NULL)
    {
        temp->data = poly2->data;
        temp->exp = poly2->exp;
        curr = (node *)malloc(sizeof(node)); 
        temp->ptr = curr;
        temp = curr;   
        poly1 = poly1->ptr;
    }
    return start;
}
