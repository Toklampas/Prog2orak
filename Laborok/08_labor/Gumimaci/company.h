#pragma once
#include "partner.h"
#include <string>

using namespace std;

class Company : public Partner {
	string businessName;

	// Value Added Tax Identifier Number
	// A nevében ugyan Number van, viszont tipikusan string szokott lenni.
	string VATIN;
public:
	Company();
	Company(const Company& theOther);
	Company(const string pBusinessName, const string pVATIN);

	~Company();

	string getBusinessName() const;
	string getVATIN() const;

	void setBusinessName(const string pBusinessName);
	void setVATIN(const string pVATIN);
};

