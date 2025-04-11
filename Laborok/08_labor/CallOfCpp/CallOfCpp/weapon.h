#pragma once
#include <string>

using namespace std;

class Weapon {
protected:
	unsigned damage;

public:
	Weapon(unsigned = 10);
	unsigned getDamage() const;
	void setDamage(unsigned);

	string toString();
	unsigned use();
};
