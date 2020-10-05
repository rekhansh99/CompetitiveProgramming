#include<stdio.h>
#include<stdlib.h>
int sum_lower(int row, int col, int *arr)
{
	int sum = 0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(i<=j)
			{
				printf("%d\n",*(arr+(i*col)+j));
				sum += *(arr+(i*col)+j);
			}
		}
	}
	return sum;
}
int sum_upper(int row, int col, int *arr)
{
	int sum = 0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(i>=j)
			{
				printf("%d\n",*(arr+(i*col)+j));
				sum += *(arr+(i*col)+j);
			}
		}
	}
	return sum;
}
int main()
{
	int row, col;
	printf("Enter your rows and columns:");
	scanf("%d %d",&row, &col);

	int arr[row][col];
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int upper, lower;
	upper = sum_upper(row, col, &arr[0][0]);
	printf("------\n");
	lower = sum_lower(row, col, &arr[0][0]);
	printf("Upper: %d\n Lower: %d",upper, lower);
}
