#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	printf("Enter total number to be input");
	scanf("%d",&num);
	int *arr;
	arr = (int *)malloc(num * sizeof(int));
	for(int i=0; i<num; i++)
		scanf("%d",arr++);
	arr = arr - num;
	int sum = 0;
	for(int i=0; i<num; i++)
	{
		sum = sum + *(arr);
		arr = arr + 1;
	}
	printf("\n%d\n",sum);
}
