#pragma once
#include <iostream>



class Complex
{
	double re;
	double im;
public:
	Complex(double pre = 0, double pim = 0);
	void print();
	~Complex();

	double getRe() const { return re; }
	double getIm() const { return im; }

	Complex operator+(const Complex& z2);
	Complex operator-(const Complex& z2);
	Complex operator-() const;

	Complex& operator++();
	Complex& operator++(int);

};

Complex operator+(const double d, const Complex& z2);

