#include "Fraction.h"
#include <string>

using namespace std;

//Konstruktor
Fraction::Fraction(int whole, int num, int denom) : wholePart(whole), numerator(num), denominator(denom){
	if (denom == 0)
		throw FractionException("Denominator cannot be zero!");
}

//Konverzios operatorok: double es string
Fraction::operator double() const
{
	return wholePart + static_cast<double>(numerator / denominator);
}

Fraction::operator string() const
{
	return to_string(wholePart) + " " + to_string(numerator) + "/" + to_string(denominator);
}

//Operator+ fuggveny
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

//Konverzios konstruktor
Fraction::Fraction(double theOther)
{
    bool isNegative = theOther < 0;
    theOther = std::abs(theOther);

    wholePart = static_cast<int>(theOther);
    double fractionalPart = theOther - wholePart;

    numerator = 0;
    denominator = 1;

    while (std::abs(fractionalPart - static_cast<double>(numerator) / denominator) > EPSILON)
    {
        denominator++;
        numerator = static_cast<int>(fractionalPart * denominator);
    }

    int gcd = find_gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (isNegative)
    {
        if (wholePart > 0)
            wholePart = -wholePart;
        else 
            numerator = -numerator;
    }
}

int Fraction::find_gcd(int a, int b) const
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction Fraction::reciprocal() const
{
    int numerator = this->getWholePart() * this->getDenominator() + this->getNumerator();
    if (numerator == 0) {
        throw FractionException("Cannot calculate reciprocal of zero.");
    }
    return Fraction(0, this->getDenominator(), numerator);
}
