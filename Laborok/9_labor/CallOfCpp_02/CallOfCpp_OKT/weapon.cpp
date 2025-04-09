#include "weapon.h"

using namespace std;

Weapon::Weapon(unsigned damage = 10): damage(damage) {}

Weapon::~Weapon(){}

unsigned Weapon::getDamage() const
{
	return damage;
}

void Weapon::setDamage(unsigned damage) {
	if (damage < 100)
		this->damage = damage;
}

ostream& operator<<(ostream& os, const Weapon* right)
{
	// Ha nem nullptr-ra mutató weapont szeretnénk kiíratni.
	if(right)
		os << right->toString();
	else os << "no weapon";
	return os;
}
