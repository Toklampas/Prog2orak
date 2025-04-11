#pragma once
#include "weapon.h"

class Knife : public Weapon
{
	double sharpness; // élességi koefficiens: [0;1]
public:
	Knife(unsigned damage = 30, double sharpness = 0.8);

	double getSharpness() const;

	unsigned use();
	void sharpen(); // élez

	std::string toString() const;
};

