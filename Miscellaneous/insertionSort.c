#include<stdio.h>

void insertionSort(int *arr, int n)
{
	int i, j, k;
	for(i = 1; i < n; i++)
	{
		k = arr[i];
		j = i-1;
		
		while(j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = k;
	}
}


int main()
{
	int l,i;
	printf("Enter size of list\n");
	scanf("%d",&l);
	int arr[l];
	
	for(i = 0; i < l; i++)
		scanf("%d", &arr[i]);
	
	insertionSort(arr, l);
	
	printf("Sorted array: \n");
	for(i = 0; i < l; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
