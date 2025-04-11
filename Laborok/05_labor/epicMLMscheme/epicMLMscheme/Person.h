#pragma once
#include <string>

using namespace std;

class Person
{
	string lastName;
	string firstName;
	char taxId[10];
	char privateKey[2000+1];
	const Person* contact;

public:
	Person(string lastName, string firstName);
	Person(string lastName, string firstName, char *taxId);
	Person(const Person& theOther);

	string getLastName();
	string getFirstName();
	const char* getTaxId();
	const Person& getContact();

	void setLastName(string lastName);
	void setFirstName(string firstName);
	void setTaxId(const char* taxId);
	void setContact(const Person& contact);

	void generatePrivateKey();
	void print();
};

const char charSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int charNum = sizeof(charSet);
char randomChar();

