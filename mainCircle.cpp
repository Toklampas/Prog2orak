#include "Circle.h"
#include <stdio.h>

int main()
{
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
}
