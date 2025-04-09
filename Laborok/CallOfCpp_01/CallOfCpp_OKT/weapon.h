#pragma once
#include <string>

class Weapon
{
protected:
	unsigned damage; // sebzés
public:
	Weapon(unsigned damage = 10);
	virtual ~Weapon();
	
	unsigned getDamage() const;
	void setDamage(unsigned damage);

	virtual unsigned use() = 0; // visszaadja a csökkentett sebzést
	
	virtual std::string toString() const = 0;
};