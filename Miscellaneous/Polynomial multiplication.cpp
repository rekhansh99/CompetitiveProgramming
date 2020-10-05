
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int pow;
	int exp;
	node *ptr;
}node;
node *create_poly();
node *multi_poly(node *, node *);
void display(node *);
int main()
{
	printf("\t<<........Hello.... Welcome to world of multiplcating polynomial........>>\n");	
	node *poly1, *poly2;
	poly1 = create_poly();
	poly2 = create_poly();
	node *poly3;
	poly3 = multi_poly(poly1, poly2);
}
node *create_poly()
{
	printf("Program will take input till power and coeff is entered as -1\n");
	printf("Enter your coeffecient and power:\n");
	printf("Coeff | Power\n");
	node *start, *temp, *curr;
	int val, pwr;
	start = (node *)malloc(sizeof(node));
	temp = start;
	scanf("%d",&val);
	scanf("%d",&pwr);
	temp->exp = val;
	temp->pow = pwr;
	temp->ptr = NULL;
	while(1)
	{
		curr = (node *)malloc(sizeof(node));
		temp->ptr = curr;
		temp =  curr;
		scanf("%d",&val);
		scanf("%d",&pwr);
		if(pwr != -1 && val != -1)
		{
			curr->exp = val;
			curr->pow = pwr;
			curr->ptr = NULL;
		}
		else
			break;
	}
	display(start);
	return start;
}
void display(node *start)
{
	node *temp;
	temp = start;
	while(temp->ptr != NULL)
	{
		printf("(%d)X^%d ", temp->exp, temp->pow);
		if(temp->exp >= 0)
			printf("+");
	}
	printf("(%d)X^%d ", temp->exp, temp->pow);
}
node *multi_poly(node *poly1, node *poly2)
{
	node *start;
	return start;
}




