#pragma once
#include <iostream>
#include <string>

using namespace std;

const double EPSILON = 1e-6;


class FractionException : std::exception {
private:
    std::string message;
public:
    FractionException(const std::string& msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class Fraction {
private:
    //Tagvaltozok
    int wholePart;
    int numerator;
    int denominator;

public:
    //Konstruktor
    Fraction(int whole, int num, int denom);

    //Getterek
    int getWholePart() const { return wholePart; }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    //Konverzios operatorok: double es string
    operator double() const;
    operator string() const;

    //Operator+ fuggveny
    Fraction operator+(const Fraction& theOther);

    //Konverzios konstruktor
    Fraction(double theOther);
    int find_gcd(int a, int b) const;

    //reciprok
    Fraction reciprocal() const;
};

