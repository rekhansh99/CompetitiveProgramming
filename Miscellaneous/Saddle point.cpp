#include<stdio.h>
#include<stdlib.h>
typedef struct point{
	int row, col;
}point;
int main(){
	int row , col;
	printf("Enter your row and column: ");
	scanf("%d %d",&row, &col);
	int arr[row][col];
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			scanf("%d",&arr[i][j]);
	}
	printf("Your matrix is: \n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
	int min, max;
	point low[row], mao[col];
	for(int i=0; i<row; i++)
	{
		min = arr[i][0];
		low[i].col = 0;
		low[i].row = i;
		for(int j=0; j<col; j++){
			if(min >= arr[i][j]){
				low[i].col = j;
				low[i].row = i;
				min = arr[i][j];
			}
		}
	}
	for(int i=0; i<col; i++){
		max = arr[0][i];
		mao[i].col = i;
		mao[i].row = 0;
		for(int j=0; j<row; j++){
			if(max <= arr[j][i]){
				mao[i].col = i;
				mao[i].row = j;
				max = arr[j][i];
			}
		}
	}
	printf("so here is lowest in each row:\n");
	for(int i=0; i<row; i++)
		printf("%d     %d\n",low[i].row, low[i].col);
	printf("so, here is highest in each column:\n");
	for(int i=0; i<col; i++)
		printf("%d     %d\n",mao[i].row, mao[i].col);
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(low[i].row == mao[j].row && low[i].col == mao[j].col)
			{
				printf("So, Saddle point of matrix is : %d\n",arr[i][j]);
				break;
			}
		}
	}
	if(i != row && j != col)
		printf("No, Saddle point obtained...\n");
}
