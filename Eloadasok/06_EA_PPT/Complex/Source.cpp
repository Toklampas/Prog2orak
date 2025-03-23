#include <stdio.h>
#include <iostream>
#include "Complex.h"

using namespace std;

ostream& operator<<(ostream& os, const Complex z)
{
	os << z.getRe() << "+i*" << z.getIm();
	return os;
}

istream& operator >> (istream& is, Complex& z) 
{
	double re, im;
	is >> re;
	char c=0;
	is >> c; //+
	if (c != '+')
		is.clear(ios::failbit);
	is >> c; //i
	if (c != 'i')
		is.clear(ios::failbit);
	is >> c; //*
	if (c != '*')
		is.clear(ios::failbit);
	is >> im;
	if (is.good())
		z = Complex(re, im);
	return is;

}

int main(int argc, char* argv[]) {

	Complex z1(1.0, 1.0);
	Complex z2(2.0, 2.0);
	Complex z3;
	z3  = 9.0 + z2;
	++z3++;
	z3.print();
	Complex z4;
	z4 = z1 - z2;
	z4.print();

	cout << "The two numbers are " << z1 << " and " << z2 << endl;
	cin >> z4;
	cout << z4;

	//HF: írd meg a többi operátort!

	getchar();
	return 0;

}