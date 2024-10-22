#include<stdio.h>
int fact(int no);
void main()
{
	int no,f;
	printf("Enter no for finding factorail");
	scanf("%d",&no);
	f=fact(no);
	printf("fact of %d is %d",no,f);
}

int fact(int no)
{
	if(no==1)
	{
		return no;
	}
	else
	{
		return no*fact(no-1);
	}
}