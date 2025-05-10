#include "Fraction.h"
#include <string>

using namespace std;

//Konstruktor

Fraction::Fraction(int whole, int num, int denom) : wholePart(whole), numerator(num), denominator(denom){
	if (denom == 0)
		throw FractionException("Denominator cannot be zero!");
}

Fraction::operator double() const
{
	return wholePart + static_cast<double>(numerator/denominator);
}

Fraction::operator string() const
{
	return to_string(wholePart) + " " + to_string(numerator) + "/" + to_string(denominator);
}

Fraction Fraction::operator+(const Fraction& theOther)
{
	int sumWholePart = this->wholePart + theOther.wholePart;
	int sumNumerator = this->numerator * theOther.denominator + theOther.numerator * this->denominator;
	int sumDenominator = this->denominator * theOther.denominator;

	if (sumNumerator >= sumDenominator)
	{
		sumWholePart += sumNumerator / sumDenominator;
		sumNumerator = sumNumerator % sumDenominator;
	}

	return Fraction(sumWholePart, sumNumerator, sumDenominator);
}

Fraction::Fraction(double theOther)
{
	// wholePart int de a theOther double -> castolni kell
	wholePart = static_cast<int>(theOther);
	theOther = theOther - wholePart;

	while (true)
	{
		return;
	}
}

//Konverzios operatorok: double es string

//Operator+ fuggveny

//Konverzios konstruktor


