#include "weapon.h"
#include <sstream>

Weapon::Weapon(unsigned damage): damage(damage){}

Weapon::~Weapon()
{
}

unsigned Weapon::getDamage() const
{
	return damage;
}

//unsigned Weapon::use()
//{
//	return --damage;
//}

void Weapon::setDamage(unsigned damage) {
	if (damage <= 100)
		this->damage = damage;
}

//std::string Weapon::toString() const
//{
//	std::stringstream ss;
//	ss << "Weapon; damage can be caused=" << getDamage();
//	return ss.str();
//}
