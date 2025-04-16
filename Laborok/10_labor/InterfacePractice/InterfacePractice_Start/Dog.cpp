#include "Dog.h"

using namespace std;

Dog::Dog(string name, unsigned char age) : name(name), age(age)
{
}

void Dog::serialize(ostream& os) const
{
	os << name << ';' << (int)age << std::endl;
}

void Dog::deserialize(std::istream& is)
{
	string name;
	int age;
	char c;

	is >> name;
	is >> c;
	if (c != ';')
		is.clear(ios::failbit);

	is >> age;

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
