#include <stdio.h>

void quickSort(int *arr, int start, int end)
{
	int pivot = arr[start];
	int i = start;
	int j = end+1;
	int temp;
	if(start < end)
	{
		while(i < j)
		{
			do i++; while(i < end && arr[i] < pivot);
			do j--; while(arr[j] > pivot);
			
			if(i<j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	
		temp = arr[start];
		arr[start] = arr[j];
		arr[j] = temp;
	
		quickSort(arr, start, j-1);
		quickSort(arr, j+1, end);
	
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
	
	quickSort(arr, 0, l-1);
	
	printf("Sorted array: \n");
	for(i = 0; i < l; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
