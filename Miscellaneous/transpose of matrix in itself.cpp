#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct matrix{
    int row, col, val;
}matrix;
void display(matrix mat4[])
{
	int k = 1;
	for(int i=0; i<mat4[0].row; i++)
	{
		for(int j=0; j<mat4[0].col; j++)
		{
			if(mat4[k].row == i && mat4[k].col == j && k <= mat4[0].val)
				printf("%d ",mat4[k++].val);
			else
				break;
		}
		printf("\n");
	}
}
void create(matrix mat1[])
{
	int temp;
	int k = 1;
	printf("Enter your rows and columns : ");
	scanf("%d %d",&mat1[0].row ,&mat1[0].col);
	for(int i=0; i<mat1[0].row; i++)
	{
		for(int j=0; j<mat1[0].col; j++)
		{
			scanf("%d",&temp);
			if(temp != 0)
			{
				mat1[k].row = i;
				mat1[k].col = j;
				mat1[k++].val = temp;
			}
		}
	}
	mat1[0].val = k-1;
	printf("\n<<<<< _______________________________________________ >>>>>> \n");
	printf("\nYour entered matrix : \n");
	display(mat1);	
	printf("\n<<<<< _______________________________________________ >>>>>> \n");
}
void copy(matrix mat1[], matrix mat2[])
{
    int k = 0;
    for(int i=0; i<=mat1[0].val; i++)
    {
        mat2[k].row = mat1[k].row;
        mat2[k].col = mat1[k].col;
        mat2[k].val = mat1[k].val;
        k++;
    }
}
void transpose(matrix mat[])
{
    int temp;
    for(int i=0; i<= mat[0].val; i++)
    {
        temp = mat[i].col;
        mat[i].col = mat[i].row;
        mat[i].row = temp;
    }
    int index, indo;
    int x, y, z;
    int pos;
    for(int i=1; i<=mat[0].val; i++)
    {
        indo = mat[i].col;
        index = mat[i].row;
        for(int j=i; j<=mat[0].val; j++)
        {
            if(index > mat[j].row && indo > mat[j].col)
            {
                index =  mat[j].row;
                indo = mat[j].col;
                pos = j;
            }
        }
        x = mat[pos].row;
        y = mat[pos].col;
        z = mat[pos].val;
        mat[pos].row = mat[i].row;
        mat[pos].col = mat[i].col;        
        mat[pos].val = mat[i].val;
        mat[i].row =  x;   
        mat[i].col =  y; 
        mat[i].val =  z;         
    }
}
int main()
{
    matrix mat1[max], mat2[max];
    create(mat1);
    copy(mat1, mat2);
    transpose(mat2);
    // display(mat1);
    printf("your transpose will be: \n"); tran
    display(mat2);
}