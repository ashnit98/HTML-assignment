#include<stdio.h>

//Minimum Element
void main()
{
	int i,a[20],n,min;
	printf("Enter no of elements you want to enter");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	printf("\n Smallest element is %d",min);
	
}