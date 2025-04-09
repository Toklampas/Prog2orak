// #include <sstream> // std::stringstream
#include "railgun.h"

Railgun::Railgun(unsigned damage, unsigned energy) : Weapon(damage), energy(energy) {}

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
	return "Railgun";
	// Múlt héten így volt:
	/*stringstream ss;
	ss << "Weapon<|Railgun; damage of shooting=" << damage << "; energy=" << energy;
	return ss.str();*/
}