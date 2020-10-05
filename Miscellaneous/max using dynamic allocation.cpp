#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr;
	printf("Enter number of terms:");
	int num;
	scanf("%d",&num);
	ptr = (int *)malloc(num * (sizeof(int)));
	for(int i=0; i<num; i++)
		scanf("%d",(ptr+i));
	int max = -99999;
	for(int i=0; i<num; i++)
	{
		if(max < ptr[i])
		{
			max = ptr[i];
		}
	}
	printf("Max of all is: %d",max);
}
