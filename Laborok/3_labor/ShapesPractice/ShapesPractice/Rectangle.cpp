#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(double a)
{
	this->a = 0;
	seta(a);
	this->b = 0;
	setb(a);
}

Rectangle::Rectangle(double a, double b)
{
	this->a = 0;
	seta(a);
	this->b = 0;
	setb(b);
}

double Rectangle::geta()
{
	return a;
}

double Rectangle::getb()
{
	return b;
}

void Rectangle::seta(double a)
{
	if (a >= 0)
		this->a = a;
}

void Rectangle::setb(double b)
{
	if (b >= 0)
		this->b = b;
}

double Rectangle::getPerimeter()
{
	return 2 * a + 2 * b;
}

double Rectangle::getArea()
{
	return a * b;
}

void Rectangle::print()
{
	printf("a = %.2lf, b = %.2lf\n", a, b);
}