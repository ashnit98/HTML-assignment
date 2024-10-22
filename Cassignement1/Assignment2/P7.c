#include<stdio.h>
int palindrome(int no);
void main()
{
	int n;
	printf("Enter number");
	scanf("%d",&n);
	if(palindrome(n))
	{
		printf(" \n %d is palindrome",n);
	}
	else
	{
		printf("\n %d is not paindrome",n);
		
	}
}

int palindrome(int no)
{
	int orig_no,rev=0,mod;
	orig_no=no;
	while(no>0)
	{
		mod=no%10;
		rev=rev*10+mod;
		no=no/10;
	}
	printf(" \n Reverse no is %d",rev);
	if(orig_no==rev)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}