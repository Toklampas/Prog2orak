#pragma once

#include "comparable.h"
#include "serializable.h"

using namespace std;

class Dog : public Comparable, public Serializable
{
	string name;
	unsigned char age;

public:
	Dog(string name, unsigned char age);

	string getName() const;
	unsigned char getAge() const;

	void setName(const string& newName);
	void setAge(unsigned char newAge);

	void serialize(ostream& os) const;
	void deserialize(istream& is);

	bool operator==(const Comparable& other) const;
	bool operator<(const Comparable& other) const;
};

ostream& operator<<(ostream& os, const Dog& right);

