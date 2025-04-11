#pragma once
#include <string>
#include <iostream>

class Weapon
{
protected:
	unsigned damage; // sebzés
public:
	Weapon(unsigned damage);
	
	// Akkor szükséges virtuális destruktor, ha
	// valamelyik leszármazott dinamikusan kezel adatot.
	virtual ~Weapon();

	unsigned getDamage() const;
	void setDamage(unsigned damage);

	// tisztán virtuális függvény, mert
	//   1) nincs értelme definiálni itt
	//   2) következmény: absztrakt osztály
	//   3) a leszármazott definíciója lesz érvényes (late binding)
	virtual unsigned use() = 0; // visszaadja a csökkentett sebzést
	
	// tisztán virtuális függvény, mert
	//   1) nincs értelme definiálni itt
	//   2) következmény: absztrakt osztály
	//   3) a leszármazott definíciója lesz érvényes (late binding)
	virtual std::string toString() const = 0;
};

std::ostream& operator<<(std::ostream&, const Weapon*);