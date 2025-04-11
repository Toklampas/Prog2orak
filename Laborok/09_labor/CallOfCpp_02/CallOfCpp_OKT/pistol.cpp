// #include <sstream> // std::stringstream
#include "pistol.h"

using namespace std;

Pistol::Pistol(unsigned damage, unsigned clipSize, unsigned bulletsInClip, unsigned totalBullets) : Weapon(damage), clipSize(clipSize), bulletsInClip(bulletsInClip), totalBullets(totalBullets) {}

unsigned Pistol::getClipSize() const
{
	return clipSize;
}

unsigned Pistol::getTotalBullets() const
{
	return totalBullets;
}

unsigned Pistol::getBulletsInClip() const
{
	return bulletsInClip;
}

unsigned Pistol::use() {
	if (bulletsInClip) {
		bulletsInClip--;
		return damage;
	}

	return 0;
}

void Pistol::reload()
{
	while (bulletsInClip < clipSize && totalBullets) { bulletsInClip++; totalBullets--; }
}

string Pistol::toString() const
{
	return "Pistol";
	// Múlt héten így volt:
	/*stringstream ss;
	ss << "Weapon<|Pistol; damage of a bullet=" << damage << "; clipSize=" << clipSize << "; bulletsInClip=" << bulletsInClip << "; totalBullets=" << totalBullets;
	return ss.str();*/
}