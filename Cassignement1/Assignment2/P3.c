#include<stdio.h>
void main()
{
	int i,j;
	int rows,cols;
	int a[10] [10];
	int b[10][10];
	int c[10][10];
	printf("Enter no of rows");
	scanf("%d",&rows);
	printf("Enter no of columns");
	scanf("%d",&cols);
	printf("\n input value for a[] []");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("Enter element at index [%d] [%d]",i,j);
			scanf("%d",&a[i][j]);
		}
		
	}
	
		printf("\n input value for b[] []");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("Enter element at index [%d] [%d]",i,j);
			scanf("%d",&b[i][j]);
		}
		
		
	}
	printf("\n Print value for a");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n Print value for b");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf(" %d ",b[i][j]);
		}
		printf("\n");
	}
	
	printf("\n Add two matrix");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	
	printf("\n Print value for c");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf(" %d ",c[i][j]);
		}
		printf("\n");
	}
}