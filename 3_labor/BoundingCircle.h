#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include <math.h>

class BoundingCircle
{
	Rectangle innerSquare;
	Circle outerCircle;

public:
	BoundingCircle(double = 1);
	Rectangle getInnerSquare();
	Circle getOuterCircle();

};

