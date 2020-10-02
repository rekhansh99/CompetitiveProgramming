#include<stdio.h>

void selectionSort(int *arr, int n)
{
	int i, mindex, j, temp;
	for(i = 0; i < n-1; i++)
	{
		mindex = i;
		for(j = i + 1; j < n; j++)
		{
			if(arr[mindex] > arr[j])
				mindex = j;
		}
			
		temp = arr[i];
		arr[i] = arr[mindex];
		arr[mindex] = temp;
	}
}


int main()
{
	int l, i;
	printf("Enter size of list\n");
	scanf("%d", &l);
	int arr[l];
	
	for(i = 0; i < l; i++)
		scanf("%d", &arr[i]);
	
	selectionSort(arr, l);
	
	printf("Sorted array: \n");
	for(i = 0; i < l; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
