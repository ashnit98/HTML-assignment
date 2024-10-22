#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
	c=a;
	a=b;
	b=c;
	printf("Value of A is %d",a);
	printf("Value of B is %d",b);
	
}




