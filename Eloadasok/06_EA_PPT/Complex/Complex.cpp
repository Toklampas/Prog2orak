#include "Complex.h"
#include <iostream>

using namespace std;


Complex::Complex(double pre, double pim)
{
	//Vagy inicializacios listaban
	re = pre;
	im = pim;
}

//Erre persze lesz sokkal jobb otletunk
void Complex::print()
{
	cout << "Re: " << re << ", Im: " << im << endl;
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex& z2)
{
	Complex res(re + z2.re, im + z2.im);
	return res;
}

Complex Complex::operator-(const Complex& z2)
{
	
	return *this + (-z2);
}

Complex Complex::operator-() const
{
	return Complex(-re, -im);
}

Complex& Complex::operator++()
{
	re++;
	return *this;
}

Complex& Complex::operator++(int)
{
	im++;
	return *this;
}

Complex operator+(const double d, const Complex& z2)
{
	return Complex(d + z2.getRe(),  z2.getIm());
}


