#include <stdio.h>
int main ()
{
	int arr[10];
	printf("Enter the elements of the array:\n");
	for (int i=0;i<10;i++)
	{
		scanf("%d ",&arr[i]);
	}
	int b,n=0;
	printf("Enter the number to be searched:");
	scanf("%d",&b);
	for (int i=0;i<10;i++)
	{
		if (arr[i]==b)
		{
			n=i;
		}
	}
	if (n>0)
	{
		printf("Element found at  th position");
	}
	else
	{
		printf("Element not found");
	}
	return 0;
}