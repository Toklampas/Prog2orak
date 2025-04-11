#pragma once
#include "weapon.h"

class Railgun : public Weapon
{
	unsigned energy; // lövéshez szükséges energia: [0;100]
public:
	Railgun(unsigned damage = 90, unsigned energy = 100);
	
	unsigned getEnergy() const;

	unsigned use();
	void recharge(); // fegyver feltöltése

	std::string toString() const;
};

