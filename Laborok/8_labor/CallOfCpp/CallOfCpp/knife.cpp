#include "knife.h"
#include <sstream>

Knife::Knife(unsigned damage, double psharpness)
	: Weapon(damage), sharpness(psharpness)
{}

void Knife::sharpen()
{
	if (sharpness < 1)
		sharpness *= 1.1;
	else
		sharpness = 1;
}

unsigned Knife::use()
{
	damage *= sharpness;
	sharpness *= 0.95;
	return damage;
}

double Knife::getSharpness() const
{
	return sharpness;
}

void Knife::setSharpness(double psharpness)
{
	if (psharpness >= 0 && psharpness <= 1.0)
		sharpness = psharpness;
}

std::string Knife::toString()
{
	std::stringstream ss;
	ss << "Weapon<|Knife; damage can be caused when stabbing=" << getSharpness()*getDamage() << "; sharpness=" << getSharpness();
	return ss.str();
}

