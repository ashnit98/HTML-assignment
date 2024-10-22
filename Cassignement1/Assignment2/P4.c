#include<stdio.h>
void main()
{
	int a[5][5];
	int i,j;
	int r,c;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter value for [%d][%d] index",i,j);
			scanf("%d",&a[i][j]);
		}
		
	}
	
	printf("Enter row index");
	scanf("%d",&r);
	printf("Enter col index");
	scanf("%d",&c);
	
	
	printf("Value is %d",a[r][c]);
	
}