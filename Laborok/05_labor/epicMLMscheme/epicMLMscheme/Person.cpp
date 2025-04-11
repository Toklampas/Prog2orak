#include "Person.h"
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

Person::Person(string lastName, string firstName) : lastName(lastName), firstName(firstName)
{
	setTaxId("");
	contact = nullptr;
	generatePrivateKey();
}

Person::Person(string lastName, string firstName, char* taxId) : lastName(lastName), firstName(firstName)
{
	setTaxId(taxId);
	contact = nullptr;
	generatePrivateKey();
}

Person::Person(const Person& theOther)
{
	generatePrivateKey();
	this->lastName = theOther.lastName;
	this->firstName = theOther.firstName;
	setTaxId(theOther.taxId);
}


string Person::getLastName()
{
	return lastName;
}

string Person::getFirstName()
{
	return firstName;
}

const char* Person::getTaxId()
{
	return taxId;
}

const Person& Person::getContact()
{
	return *contact;
}

void Person::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Person::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Person::setTaxId(const char* taxId)
{
	if(strlen(taxId) == 10) // hibakezelés
		strcpy_s(this->taxId, sizeof(taxId), taxId);
	else
		strcpy_s(this->taxId, 1, "");
}

void Person::setContact(const Person& contact)
{
	this->contact = &contact;
}

char randomChar()
{
	return charSet[rand() % charNum];
}

void Person::generatePrivateKey()
{
	int size = sizeof(privateKey);
	for (int i = 0; i < 2000; i++)
	{
		privateKey[i] = randomChar();
	}
	privateKey[size - 1] = '\0';

}

void Person::print()
{
	printf("Firstname: %s, Lastname: %s, taxId: %s, Contact taxId: %s", firstName.c_str(), lastName.c_str(), taxId, contact->taxId);
}
