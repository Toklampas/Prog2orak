#include "Circle.h"
#include "Rectangle.h"
#include "BoundingCircle.h"
#include <stdio.h>

int main()
{
	printf("Testing Rectangle...\n");
	Rectangle r1;
	Rectangle r2(4);
	Rectangle r3(2, 5);
	r1.print(); // a=0.00, b=0.00 
	r2.print(); // a=4.00, b=4.00 
	r3.print(); // a=2.00, b=5.00 
	printf("Area of r1=%.2lf\n", r1.getArea()); // Area of r1=0.00 
	printf("Area of r2=%.2lf\n", r2.getArea()); // Area of r2=16.00 
	printf("Area of r3=%.2lf\n", r3.getArea()); // Area of r3=10.00 
	printf("Perimeter of r1=%.2lf\n", r1.getPerimeter()); // Perimeter of r1=0.00 
	printf("Perimeter of r2=%.2lf\n", r2.getPerimeter()); // Perimeter of r2=16.00 
	printf("Perimeter of r3=%.2lf\n", r3.getPerimeter()); // Perimeter of r3=14.00 
	r3.seta(r2.geta());
	r3.setb(r2.getb());
	r3.print(); // a=4.00, b=4.00 
	printf("Area of r3=%.2lf\n", r3.getArea()); // Area of r3=16.00 
	printf("Perimeter of r3=%.2lf\n", r3.getPerimeter()); // Perimeter of r3=16.00 


	printf("\nTesting Circle...\n");
	Circle c1;
	Circle c2(10);
	c1.print(); // r=0.00 
	c2.print(); // r=10.00 
	printf("Area of c1=%.2lf\n", c1.getArea()); // Area of c1 = 0.00 
	printf("Area of c2=%.2lf\n", c2.getArea()); // Area of c2 = 314.16 
	printf("Circumference of c1=%.2lf\n", c1.getCircumference()); // Circumference of c1 = 0.00 
	printf("Circumference of c2=%.2lf\n", c2.getCircumference()); // Circumference of c2 = 62.83 
	c1.setr(c2.getr());
	c1.print();
	printf("Radius of c1=%.2lf\n", c1.getr()); // Radius of c1=10.00 
	printf("Area of c1=%.2lf\n", c1.getArea()); // Area of c1=314.16 
	printf("Circumference of c1=%.2lf\n", c1.getCircumference()); // Circumference of c1=62.83


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