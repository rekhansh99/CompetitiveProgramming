#include<stdio.h>
int main()
{
	int num;
	printf("Enter digits to be inputted:");
	scanf("%d",&num);
	int arr[num];
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	int max =0, max2 =0;
	for(int i=0; i<num; i++)
	{
		if(arr[i] > max)
		{
			max2 = max;
			max = arr[i];
		}
		else if(arr[i] >max2)
		{
			max2= arr[i];
		}
	}
	printf("Max : %d\n",max);
	printf("Second Max : %d",max2);
}
