#pragma once

class Weapon {
	unsigned damage;

public:
	Weapon();

	void setDamage(unsigned pDamage);
	unsigned getDamage() const;

	unsigned use();

	void toString() const;
};