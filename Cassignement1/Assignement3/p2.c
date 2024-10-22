#include<stdio.h>
void swap(int* a,int* b);
void main()
{
	int x=10,y=20;
	swap(&x,&y);
	printf("Value of x is %d and y is %d",x,y);
}

void swap(int* a,int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}