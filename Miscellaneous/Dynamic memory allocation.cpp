#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	printf("Enter array size:");
	scanf("%d",&num);
	int *arr;
	arr = (int *)malloc(num * sizeof(int));
	printf("Enter array now!");
	for(int i=0; i<num; i++)
		scanf("%d",arr+i);
	int sum = 0;
	for(int i=0; i<num; i++)
		sum += *(arr+i);
	printf("Your sum is: %d",sum);
}
