#include "railgun.h"
#include <sstream>

Railgun::Railgun(unsigned pdamage, unsigned penergy)
	: Weapon(pdamage), energy(penergy)
{}

unsigned Railgun::getEnergy() const
{
	return energy;
}

void Railgun::recharge()
{
	if (energy + 8 > 100)
		energy = 100;
	else
		energy += 8;
}

unsigned Railgun::use()
{
	if (energy - 10 < 0)
		return 0;
	else
	{
		energy -= 10;
		return damage;
	}
}

void Railgun::setEnergy(unsigned penergy)
{
	if (penergy > 100)
		energy = 100;
	else if (penergy < 0)
		energy = 0;
	else
	energy = penergy;
}

std::string Railgun::toString()
{
	std::stringstream ss;
	ss << "Weapon<|Railgun; damage of shooting=" << getDamage() << "; energy=" << getEnergy();
	return ss.str();
}
