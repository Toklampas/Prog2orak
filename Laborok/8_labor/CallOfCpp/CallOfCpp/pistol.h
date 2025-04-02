#pragma once
#include "weapon.h"

using namespace std;

class Pistol : public Weapon {
	const unsigned clipSize;
	unsigned totalBullets;
	unsigned bulletsInClip;

public:

	Pistol(unsigned pdamage = 60, unsigned pclipSize = 12, unsigned ptotalBullets = 36);

	const unsigned getClipSize() const;
	unsigned getTotalBullets() const;
	unsigned getBulletsInClip() const;

	void setTotalBullets(unsigned ptotalBullets);
	void setBulletsInClip(unsigned pbulletsInClip);
	
	unsigned use();
	void reload();
	string toString();
};