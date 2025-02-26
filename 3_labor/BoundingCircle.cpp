#include "BoundingCircle.h"
#include <stdio.h>
#include <math.h>

BoundingCircle::BoundingCircle(double a) : innerSquare(a), outerCircle(a*sqrt(2)/2)
{
	
}

Rectangle BoundingCircle::getInnerSquare()
{
	return innerSquare;
}

Circle BoundingCircle::getOuterCircle()
{
	return outerCircle;
}

double BoundingCircle::getPeimeter()
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