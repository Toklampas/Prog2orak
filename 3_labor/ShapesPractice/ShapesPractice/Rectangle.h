#pragma once
class Rectangle
{
	double a, b;

public:
	Rectangle(double a = 0); // 2 konstruktor, 0, n�gyzet
	Rectangle(double, double); // t�glalap

	double geta(); // accessor/getter
	double getb();

	void seta(double); // mutator/setter
	void setb(double);

	double getPerimeter(); // ker�let
	double getArea(); // ter�let

	void print();

};


