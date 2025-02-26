#include "Circle.h"
#include <stdio.h>

Circle::Circle(double r)
{
	this->r = r;
}

double Circle::getr()
{
	return r;
}

void Circle::setr(double r)
{
	if (r >= 0)
		this->r = r;
}

double Circle::getArea()
{
	return r * r * 3.14;
}

double Circle::getCircumference()
{
	return (r + r) * 3.14;
}

void Circle::print()
{
	printf("r = %.2lf", r);
}