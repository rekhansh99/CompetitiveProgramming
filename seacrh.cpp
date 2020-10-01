#include<stdio.h>
int binary(int [], int , int);
int linear(int [], int , int);
int Bsearch(int [], int , int , int );
int main()
{
	printf(":::This program searches the element:::\n\n");
	int num;
	printf("Enter number of elements to be entered:");
	scanf("%d",&num);
	int arr[num];
	printf("Enter your elements now!\n");
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	int search;
	printf("Enter your element to be searched:");
	scanf("%d",&search);
	int index;
	int res;
	printf("Enter your option for type of searching:\n1. Linear\n2. Binary\n");
	scanf("%d",&res);
	switch(res)
	{
		case 1: index = linear(arr, num, search);break;
		case 2: index = binary(arr, num, search);
	}
	if(index != -1)
		printf("Element is found in %d place in data",index+1);
	else
		printf("Element not found in data");	
}
int linear(int arr[], int num, int search)
{
	for(int i=0; i<num; i++)
	{
		if(arr[i] == search)
		{
			return i;
		}
	}
	return -1;
}
int binary(int arr[], int num, int search)
{
	int start = 0;
	int end = num;
	Bsearch(arr, start, end, search);
}
int Bsearch(int arr[], int start, int end, int search)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		if(arr[mid] == search)
			return mid;
		else if(arr[mid] > search)
			return (Bsearch(arr, start, mid, search));
		else
			return (Bsearch(arr, mid, end, search));
	}
	else
	{
		return -1;
	}
}
