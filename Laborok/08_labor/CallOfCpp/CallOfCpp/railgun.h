#pragma once
#include  "weapon.h"

using namespace std;

class Railgun : public Weapon {
	unsigned energy;

public:
	Railgun(unsigned pdamage = 90, unsigned penergy = 100);

	unsigned getEnergy() const;
	void recharge();
	unsigned use();
	void setEnergy(unsigned penergy);
	string toString();
};