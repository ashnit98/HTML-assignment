/*Write a program to calculate the area of circle/rectangle/triangle.
C indicate circle ,
R indicate rectangle,
T indicate triangle.
use symbolic constant to define the value of pie.*/

#include<stdio.h>

int main() {
    const float p = 3.14;
    float r, b, h;

    
    printf("\n Enter radius: ");
    scanf("%f", &r);

   
    printf("\n Enter Base and height: ");
    scanf("%f %f", &b, &h);

    
    float res;
    res = p * r * r;
    printf("\n Area of the Circle is: %f", res);

   
    res = (1.0 / 2) * b * h;  
    printf("\n Area of the Triangle is: %f", res);

    return 0;
}