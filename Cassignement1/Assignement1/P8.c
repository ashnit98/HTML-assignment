#include<stdio.h>
void main()
{
	int n,mod,sum=0;
	printf("Enter a number and do reverse of it ");
	scanf("%d",&n);
	printf("Reverse no is ");
	while(n>0)
	{
		mod=n%10;
		sum=sum+mod;
		printf("%d",mod);
		n=n/10;
		
		
	}
	printf("\n Sum is %d",sum);
}