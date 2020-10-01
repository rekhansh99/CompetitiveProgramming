#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	int arr[test];
	for(int i=0; i<test; i++)
		scanf("%d",&arr[i]);
	int *ptr;
	ptr = arr;
	int avg = 0;
	for(int i=0; i<test; i++)
		avg += *(ptr+i);
//	printf("%d",avg);
	printf("Avg: %d", avg/test);
}
