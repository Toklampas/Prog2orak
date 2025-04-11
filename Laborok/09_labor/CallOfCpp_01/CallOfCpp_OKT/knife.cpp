#include "knife.h"
#include <sstream>

Knife::Knife(unsigned damage, double sharpness): Weapon(damage), sharpness(sharpness) {}

Knife::~Knife()
{
}

double Knife::getSharpness() const
{
	return sharpness;
}

unsigned Knife::use()
{
	damage *= sharpness;
	sharpness *= 0.95;
	return damage;
}

void Knife::sharpen()
{
	sharpness = sharpness < 1 ? sharpness*1.1 : 1;
}

std::string Knife::toString() const
{
	std::stringstream ss;
	ss << "Weapon<|Knife; damage can be caused when stabbing=" << sharpness*damage << "; sharpness=" << sharpness;
	return ss.str();
}