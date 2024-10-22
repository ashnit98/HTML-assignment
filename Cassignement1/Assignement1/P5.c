#include<stdio.h>
void main()
{
	float bs,da,hra,gs;
	printf("Enter your basic salary");
	scanf("%f",&bs);
	printf("Enter your Da");
	scanf("%f",&da);
	printf("Enter your Hra");
	scanf("%f",&hra);
	if(bs<1500)
	{
		da=bs*10/100;
		hra=bs*90/100;
	}
	else
	{
		da=500;
		hra=bs*98/100;
	}
	gs=da+hra+bs;
	printf("Gross salary is %f",gs);
}
