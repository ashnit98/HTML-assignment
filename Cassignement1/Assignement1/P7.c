#include<stdio.h>
void main()
{
	int n=7,flag=1,i;
	printf("Enter a no to determine no is prime or not");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
		flag=0;
		break;
		}
		
		
	}
	if(flag==0)
	printf("%d not prime",n);
	else
	printf("%d is prime",n);
}

