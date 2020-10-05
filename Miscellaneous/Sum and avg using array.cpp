#include<stdio.h>
int main()
{
	int num;
	printf("Enter digits to be inputed: ");
	scanf("%d",&num);
	int arr[num];
	float sum = 0;
	for(int i=0; i<num; i++)
	{
		scanf("%d",(arr+i));
		sum += *(arr+i);
	}
	float avg = sum/num;
	printf("Sum = %0.0f \n",sum);
	printf("Average : %0.2f",avg);
}
