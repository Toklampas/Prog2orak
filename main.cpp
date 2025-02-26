#include "rectangle.h"
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
}