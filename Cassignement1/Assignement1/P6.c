#include<stdio.h>
void main()
{
	int i,n,res;
	printf("Enter number to print multiplication table of that no");
	scanf("%d",&n);
	for(i=1;i<=10;i++)
	{
		res=n*i;
		printf(" \n  %d * %d = %d",n,i,res);
	}
	
}