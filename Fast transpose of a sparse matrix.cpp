#include<stdio.h>
#define max 100
typedef struct{
	int row;
	int col;
	int val;
}matrix;
void fast_transpose(matrix mat1[], matrix mat2[])
{
	int rowterm[mat1[0].col];
	for(int i=0; i<mat1[0].col; i++)
		rowterm[i] = 0;
	for(int i=1; i<=mat1[0].val; i++)
		rowterm[mat1[i].col]++;
	int start[mat1[0].col];
	start[0] = 1;
	for(int i=1; i<mat1[0].col; i++)
		start[i] = start[i-1] + rowterm[i-1];
	int index;
	mat2[0].col = mat1[0].row;
	mat2[0].row = mat1[0].col;
	mat2[0].val = mat1[0].val;
	for(int i=1; i<=mat1[0].val; i++)
	{
		index = start[mat1[i].col];
		mat2[index].row = mat1[i].col;
		mat2[index].col = mat1[i].row;
		mat2[index].val = mat1[i].val;
		start[mat1[i].col]++;
	}
}
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
	fast_transpose(mat1, mat2);
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
