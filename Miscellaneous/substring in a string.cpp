#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	printf("Enter number for test cases!!:");
	scanf("%d",&test);
	for(int loop=0; loop<test; loop++)
	{
		char str[200], f_str[200];
		printf("Input:\n");
		printf("Enter your main string:");
		scanf("%s",str);
		int len = strlen(str);
		printf("Enter your sub string:");
		scanf("%s",f_str);
		int f_len = strlen(f_str);
		printf("Output:\n");
		if(f_len > len)
			printf("Error 404 \n");
		else
		{
			int j;
			for(int i=0; i<len; i++)
			{
				for(j = 0; j<f_len; j++)
				{
					if(f_str[j] != str[i+j])
						break;
				}
				if(j == f_len)
					printf("Substring present at index : %d\n", i);
			}
		}
		
	}
}
