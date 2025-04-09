#pragma once
#include "weapon.h"

class Player
{
	std::string name; // a játékos neve
	unsigned health; // életerő: [0;100]
	unsigned weaponsCount; // fegyverek aktuális száma: [0;maxWeaponsCount]
	const unsigned maxWeaponsCount; // fegyverek maximális száma: [0:UINT_MAX]
	
	// Megjegyzés: két ember birtokolhatja ugyanazt a fegyvert
	Weapon** weapons; // fegyverekre mutató heterogén tömb

	unsigned selectedWeaponIndex; // kiválasztott fegyver indexe: [0;weaponsCount)
public:
	Player(std::string name = "Unknown Soldier", unsigned health = 100, unsigned maxWeaponsCount = 5, Weapon* weapon = nullptr);
	~Player();

	std::string getName() const;
	void setName(std::string name);
	unsigned getWeaponsCount() const;
	Weapon* getSelectedWeapon() const;
	unsigned getHealth() const;

	// Igazzal térnek vissza, ha sikeres a művelet, különben hamissal.
	bool equipWeapon(Weapon* weapon); // fegyver felvétele (pl. a földről)
	bool dropSelected(); // eldobja a kiválasztott fegyvert
	bool switchToNextWeapon(); // listában következő fegyverre vált (körben forgó lista)
	bool switchToPreviousWeapon(); // listában az előző fegyverre vált (körben forgó lista)
	bool takeDamage(unsigned damage); // sebződik a játékos
	bool attack(Player& enemy) const; // másik játékos sebzése a kiválasztott fegyverrel
	bool isAlive() const; // true: életben van, false: nincs életben
};

std::ostream& operator<<(std::ostream&, const Player&);