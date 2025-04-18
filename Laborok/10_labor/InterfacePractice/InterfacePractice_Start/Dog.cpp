#include "dog.h"

using namespace std;

Dog::Dog(string name, unsigned char age) : name(name), age(age)
{
}

string Dog::getName() const
{
	return name;
}

unsigned char Dog::getAge() const
{
	return age;
}

void Dog::setName(const string& pName)
{
	name = pName;
}

void Dog::setAge(unsigned char pAge)
{
	age = pAge;
}

void Dog::serialize(ostream& os) const
{
	os << (int)age << '\t' << name << std::endl;
}

void Dog::deserialize(istream& is)
{
	string name;
	int age;
	char c;

	is >> age;
	//is >> c;
	//if (c != '\t')
	//	is.clear(ios::failbit);

	is >> name;

	if (is)
	{
		this->age = age;
		this->name = name;
	}
	else
		cerr << "Error in input format." << endl;
}

bool Dog::operator==(const Comparable& other) const
{
	Dog* pOther = (Dog*)&other;
	return this->age == pOther->age;
}

bool Dog::operator<(const Comparable& other) const
{
	Dog* pOther = (Dog*)&other;
	return this->age < pOther->age;
}

ostream& operator<<(ostream& os, const Dog& right)
{
	right.serialize(os);
	return os;
}
