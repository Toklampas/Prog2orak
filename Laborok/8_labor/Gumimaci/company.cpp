#include "company.h"
#include <iostream>

using namespace std;

Company::Company() : Partner(), businessName("unknown"), VATIN("unknown")
{

}

Company::Company(const Company& theOther) : Partner(theOther)
{
	businessName = theOther.businessName;
	VATIN = theOther.VATIN;
}

Company::Company(const string pBusinessName, const string pVATIN) : Partner(), businessName(pBusinessName), VATIN(pVATIN)
{
}

Company::~Company()
{
}

string Company::getBusinessName() const
{
	return businessName;
}

string Company::getVATIN() const
{
	return VATIN;
}

void Company::setBusinessName(const string pBusinessName)
{
	businessName = pBusinessName;
}

void Company::setVATIN(const string pVATIN)
{
	VATIN = pVATIN;
}
