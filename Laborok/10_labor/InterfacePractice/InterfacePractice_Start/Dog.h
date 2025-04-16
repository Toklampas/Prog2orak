#pragma once

#include "comparable.h"
#include "serializable.h"

class Dog : public Comparable, public Serializable
{
	std::string name;
	unsigned char age;

public:
	Dog(std::string name, unsigned char age);

	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);

	bool operator==(const Comparable& other) const;
	bool operator<(const Comparable& other) const;
};

std::ostream& operator<<(std::ostream& os, const Dog& right);

