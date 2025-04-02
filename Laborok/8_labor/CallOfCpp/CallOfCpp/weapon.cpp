#include "weapon.h"
#include <sstream>
using namespace std;

Weapon::Weapon(unsigned pdamage) : damage(pdamage)
{}

unsigned Weapon::getDamage() const
{
	return damage;
}

void Weapon::setDamage(unsigned pdamage)
{
	if (pdamage > 100)
		damage = 100;
	else if (pdamage < 0)
		damage = 0;
	else
		damage = pdamage;
}

string Weapon::toString()
{
	stringstream ss;
	ss << "Weapon; damage can be caused=" << getDamage();
	return ss.str();
}

unsigned Weapon::use()
{
	return --damage;
}

