#include "pistol.h"
#include <sstream>

Pistol::Pistol(unsigned pdamage, unsigned pclipSize, unsigned ptotalBullets)
	: Weapon(pdamage), clipSize(pclipSize), bulletsInClip(pclipSize), totalBullets(ptotalBullets)
{}

const unsigned Pistol::getClipSize() const
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

void Pistol::setTotalBullets(unsigned ptotalBullets)
{
	totalBullets = ptotalBullets;
}

void Pistol::setBulletsInClip(unsigned pbulletsInClip)
{
	if (pbulletsInClip <= clipSize)
		bulletsInClip = pbulletsInClip;

}

unsigned Pistol::use()
{
	if (bulletsInClip)
	{
		bulletsInClip--;
		return damage;
	}

	return 0;
}

void Pistol::reload()
{
	while (bulletsInClip < clipSize && totalBullets)
	{
		bulletsInClip++;
		totalBullets--;
	}
}

std::string Pistol::toString()
{
	std::stringstream ss;
	ss << "Weapon<|Pistol; damage of a bullet=" << getDamage() << "; clipSize=" << getClipSize() << "; bulletsInClip=" << getBulletsInClip() << "; totalBullets=" << getTotalBullets();
	return ss.str();
}




