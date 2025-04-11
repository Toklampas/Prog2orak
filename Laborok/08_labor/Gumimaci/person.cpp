#include "person.h"
#include <iostream>

using namespace std;

Person::Person(): Partner(), firstName("unknown"), lastName("unknown"), taxNumber("unknown")
{
}

Person::Person(const Person& theOther) : Partner(theOther)
{
	generatePrivateKey();
	firstName = theOther.firstName;
	lastName = theOther.lastName;
	taxNumber = theOther.taxNumber;
}

Person::Person(const string pFirstName, const string pLastName, const string pTaxNumber) : Partner(), firstName(pFirstName), lastName(pLastName), taxNumber(pTaxNumber)
{
	generatePrivateKey();
}

Person::~Person()
{
}

string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}

string Person::getTaxNumber() const
{
	return taxNumber;
}

void Person::setFirstName(const string pFirstName)
{
	firstName = pFirstName;
}

void Person::setLastName(const string pLastName)
{
	lastName = pLastName;
}

void Person::setTaxNumber(const string pTaxNumber)
{
	taxNumber = pTaxNumber;
}
