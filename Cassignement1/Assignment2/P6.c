#include<stdio.h>
int prime(int no);
void main()
{
	int n;
	printf("Enter number");
	scanf("%d",&n);
	
	if (prime(n)){
	printf("No %d is prime",n);	
	}
	else
	{
	printf(" No %d is not prime",n);	
	}
	
}

int prime(int no)
{
	int i,flag=1;
	if (no<2)
	{
		flag=0;
		return 0;
	}
	
	for(i=2;i<no;i++)
	{
		if(no%i==0)
		{
			return 0;
		}
	}
	
	if(flag==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}