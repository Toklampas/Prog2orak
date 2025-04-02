#include "weapon.h"

Weapon::Weapon() : damage(10)
{
}

void Weapon::setDamage(unsigned pDamage)
{
	if (pDamage >= 0 && pDamage <= 100)
		damage = pDamage;
	else if (pDamage < 0)
		damage = 0;
	else
		damage = 100;
}

unsigned Weapon::getDamage() const
{
	return damage;
}

unsigned Weapon::use()
{
	if (damage > 0)
		damage--;
	return damage;
}

void Weapon::toString() const
{
}
