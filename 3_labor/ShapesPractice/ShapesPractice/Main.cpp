#include "Circle.h"
#include "Rectangle.h"
#include "BoundingCircle.h"
#include <stdio.h>

int main()
{
	printf("\nTesting BoundingCircle...\n");
	BoundingCircle b1;
	BoundingCircle b2(10);
	b1.print(); // inner square: a=1.00, b=1.00\nouter circle: r=0.71 
	b2.print(); // inner square: a=10.00, b=10.00\nouter circle: r=7.07 
	printf("Area of c1=%.2lf\n", b1.getArea()); // Area of c1=0.57 
	printf("Area of c2=%.2lf\n", b2.getArea()); // Area of c2=57.08 
	printf("Perimeter of c1=%.2lf\n", b1.getPerimeter()); // Perimeter of c1=8.44 
	printf("Perimeter of c2=%.2lf\n", b2.getPerimeter()); // Perimeter of c2=84.43 
	b1.getInnerSquare().print(); // a=1.00, b=1.00 
	b1.getOuterCircle().print(); // r=0.71
}