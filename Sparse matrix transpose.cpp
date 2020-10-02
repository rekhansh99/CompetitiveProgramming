#include<stdio.h>
typedef struct{
	int row;
	int col;
	int val;
}matrix;
#define max 100
int main()
{
	matrix mat1[max], mat2[max];
	printf("Enter your number of rows: ");
	scanf("%d",&mat1[0].row);
	printf("Enter number of columns: ");
	scanf("%d",&mat1[0].col);
	int k =1;
	int temp;
	for(int i=0; i<mat1[0].row; i++)
	{
		for(int j=0; j<mat1[0].col; j++)
		{
			scanf("%d",&temp);
			if(temp != 0)
			{
				mat1[k].val = temp;
				mat1[k].row = i;
				mat1[k++].col = j;
			}
		}
	}
	mat1[0].val = k-1;
	k = 1;
	mat2[0].row = mat1[0].col;
	mat2[0].col = mat1[0].row;
	mat2[0].val = mat1[0].val;
	for(int i=0; i<mat1[0].col; i++)
	{
		for(int j=1; j<=mat1[0].val; j++)
		{
			if(mat1[j].col == i)
			{
				mat2[k].row = mat1[j].col;
				mat2[k].col = mat1[j].row;
				mat2[k].val = mat1[j].val;
				k++;		
			}
		}
	}
	k = 1;
	printf("\n");
	k = 1;
	printf("You entered matrix : \n");
	for(int i=0; i<mat1[0].row; i++)
	{
		for(int j=0; j<mat1[0].col; j++)
		{
			if(i == mat1[k].row && j == mat1[k].col)
				printf("%d ",mat1[k++].val);
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("Your transpose matrix is: \n");
	k = 1;
	for(int i=0; i<mat2[0].row; i++)
	{
		for(int j=0; j<mat2[0].col; j++)
		{
			if(i == mat2[k].row && j == mat2[k].col)
				printf("%d ",mat2[k++].val);
			else
				printf("0 ");
		}
		printf("\n");
	}
	
}
