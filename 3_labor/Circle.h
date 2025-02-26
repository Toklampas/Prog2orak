#pragma once
class Circle
{
	double r;
	
public:
	Circle(double r = 0);

	double getr();

	void setr(double);

	double getArea();
	double getCircumference();

	void print();
};

