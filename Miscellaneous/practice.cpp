#include<stdio.h>
#include<stdlib.h>
void selection(int *arr, int num)
{
	int index;
	for(int i=0; i<num; i++)
	{
		index = i;
		for(int j=i; j<num; j++)
		{
			if(arr[index] > arr[j])
				index = j;
		}
		int temp;
		temp =  arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}
void qsort(int *arr, int start, int end)
{
	if(start < end)
	{
		int pivot = arr[start];
		int i=0, j = end;
		while(i<j)
		{
			do{i++;} while(arr[i] < pivot && i<end);
			do{j--;} while(arr[j] > pivot);
			if(i<j)
			{
				int temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		int temp;
		temp = arr[j];
		arr[j] = arr[start];
		arr[start] = temp;
		qsort(arr, start, j-1);
		qsort(arr, j+1, end);
	}
}
void quick(int *arr, int num)
{
	qsort(arr, 0, num);
}
void insertion(int *arr, int num)
{
	for(int i=1; i<num; i++)
	{
		if(arr[i] < arr[i-1])
		{
			int temp;
			temp = arr[i];
			for(int j = i-1; j >= 0; j--)
			{
				if(arr[j-1] > temp)
				{
					arr[j+1] = arr[j];
				}
				else
				{
					arr[j+1] = arr[j];
					arr[j] = temp;
					break;
				}
			}
		}
	}
}

void merge(int *arr, int start, int mid, int end)
{
	int i,j,k;
	int len = end-start+1;
	int temp[len];
	i = start; 
	k = 0;
	j = mid+1;
	while(i<=mid && j<=end)
	{
		if(arr[i] > arr[j])
			temp[k++] = arr[j++];
		else
			temp[k++] = arr[i++];
	}
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j<=end)
		temp[k++] = arr[j++];
	k = 0;
	for(int i=start; i<=end; i++)
		arr[i] = temp[k++];
}
void msort(int *arr, int start, int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		msort(arr, start, mid);
		msort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
void mergesort(int *arr, int num)
{
	msort(arr, 0,num-1);
}

void sort(int *arr, int num)
{
	printf("Choice : \n");
	printf("1. Selection sort\n");
	printf("2. Quick sort\n");
	printf("3. Insertion sort\n");
	printf("4. Merge sort\n");
	printf("5. Bubble sort\n");
	printf("6. Heap Sort\n");
	int ans;
	scanf("%d",&ans);
	switch(ans)
	{
		case 1:selection(arr, num);break;
		case 2:quick(arr, num);break;
		case 3:insertion(arr, num);break;
		case 4:mergesort(arr, num);break;
//		case 5:bubble(arr[num], num);break;
//		case 6:heap(arr[num], num);break;
	}
}
int main()
{
	int num;
	printf("Enter number of elements:");
	scanf("%d",&num);
	printf("Keep entering elements...\n");
	int arr[num];
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	sort(arr, num);
	printf("Sorted : \n");
	for(int i=0; i<num; i++)
		printf("%d\n",arr[i]);
}
