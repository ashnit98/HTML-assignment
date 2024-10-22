#include<stdio.h>

//Maximum Element
void main()
{
	int i,a[20],n,max;
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
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("\n Largest element is %d",max);
	
}
