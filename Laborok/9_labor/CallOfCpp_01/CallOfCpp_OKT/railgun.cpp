#include "railgun.h"
#include <sstream>

Railgun::Railgun(unsigned damage, unsigned energy): Weapon(damage), energy(energy) {}

Railgun::~Railgun()
{
}

unsigned Railgun::getEnergy() const
{
	return energy;
}

unsigned Railgun::use() {
	if (energy >= 10) {
		energy -= 10;
		return damage;
	}

	return 0;
}

void Railgun::recharge() {
	energy += 8;
}

std::string Railgun::toString() const
{
	std::stringstream ss;
	ss << "Weapon<|Railgun; damage of shooting=" << damage << "; energy=" << energy;
	return ss.str();
}