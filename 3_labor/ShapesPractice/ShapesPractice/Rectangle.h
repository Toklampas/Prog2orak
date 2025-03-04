#pragma once
class Rectangle
{
	double a, b;

public:
	Rectangle(double a = 0); // 2 konstruktor, 0, négyzet
	Rectangle(double, double); // téglalap

	double geta(); // accessor/getter
	double getb();

	void seta(double); // mutator/setter
	void setb(double);

	double getPerimeter(); // kerület
	double getArea(); // terület

	void print();

};


