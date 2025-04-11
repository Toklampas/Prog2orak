#include "BoundingCircle.h"
#include <stdio.h>
#include <math.h>

BoundingCircle::BoundingCircle(double a)
{
	innerSquare.seta(1);
	innerSquare.setb(1);
	innerSquare.seta(a);
	innerSquare.setb(a);
	
	outerCircle.setr(sqrt(2) / 2);
	outerCircle.setr(a * sqrt(2) / 2);
}

Rectangle BoundingCircle::getInnerSquare()
{
	return innerSquare;
}

Circle BoundingCircle::getOuterCircle()
{
	return outerCircle;
}

double BoundingCircle::getPerimeter()
{
	return innerSquare.getPerimeter() + outerCircle.getCircumference();
}

double BoundingCircle::getArea()
{
	return outerCircle.getArea() - innerSquare.getArea();
}

void BoundingCircle::print()
{
	innerSquare.print();
	outerCircle.print();
}