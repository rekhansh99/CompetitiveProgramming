#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("Enter number of terms you want to enter:");
	int num;
	scanf("%d",&num);
	int *arr;
	arr = (int *)malloc(num * (sizeof(int)));
	int max = -99999, max2 = -9999;
	for(int i=0; i<num; i++)
	{
		scanf("%d",(arr+i));
	}
	for(int i=0; i<num; i++)
	{
		if(*(arr+i) > max)
		{
			max2 = max;
			max = *(arr+i);
		}
		else if(*(arr+i) > max2)
		{
			max2 = *(arr+i);
		}
	}
	printf("Maximum: %d\n",max);
	printf("Second max: %d",max2);
}
