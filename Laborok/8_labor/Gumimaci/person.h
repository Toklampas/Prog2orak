#pragma once
#include "partner.h"
#include <string>

using namespace std;

class Person : public Partner {
	string firstName;
	string lastName;
	string taxNumber;

public:
	Person();
	Person(const Person& theOther);
	Person(const string pFirstName, const string pLastName, const string pTaxNumber);

	~Person();

	string getFirstName() const;
	string getLastName() const;
	string getTaxNumber() const;

	void setFirstName(const string pFirstName);
	void setLastName(const string pLastName);
	void setTaxNumber(const string pTaxNumber);
};

