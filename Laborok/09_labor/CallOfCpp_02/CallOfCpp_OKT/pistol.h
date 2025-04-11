#pragma once
#include "weapon.h"

class Pistol : public Weapon
{
	const unsigned clipSize; // pisztoly tölténytára
	unsigned totalBullets; // töltény dobozban lévő töltények
	unsigned bulletsInClip; // tárban lévő töltények
public:
	Pistol(unsigned damage = 60, unsigned clipSize = 12, unsigned bulletsInClip = 12, unsigned totalBullets = 36);
	
	unsigned getClipSize() const;
	unsigned getTotalBullets() const;
	unsigned getBulletsInClip() const;

	unsigned use();
	void reload(); // tár újratöltése
	
	std::string toString() const;
};

