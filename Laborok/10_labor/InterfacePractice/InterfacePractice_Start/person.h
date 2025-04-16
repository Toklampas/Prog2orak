#pragma once

#include "comparable.h" // 1. feladat
#include "serializable.h" // 1.,3. feladat

class Person : public Comparable, public Serializable // 1. feladat
{
	unsigned char age; // Visual Studio-ban char[-128..127], egyébként implementáció függő (undefined)
	double height;
	double weight;
public:
	Person(unsigned char age, double height, double weight);

	void setAge(unsigned char age);
	// ha unsigned char-t adna vissza, mindig át kellene castolni int-té, hogy ne karaktert írjon ki
	int getAge() const;

	bool setHeight(double height);
	double getHeight() const;

	bool setWeight(double weight);
	double getWeight() const;


	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);

	bool operator==(const Comparable& other) const;
	bool operator<(const Comparable& other) const;
};

std::ostream& operator<<(std::ostream& os, const Person& right);