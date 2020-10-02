#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0; i<num; i++)
        scanf("%d",&arr[i]);
    int max = -99999;
    int index;
    for(int i=0; i<num; i=i+2)
    {
        if(arr[i]+arr[i+1]>max)
        {
        	max = (arr[i]+arr[i+1]);
        	index = i;
		}
    }
    printf("Index:%d\n Max:%d", index+1, max);
    
}
