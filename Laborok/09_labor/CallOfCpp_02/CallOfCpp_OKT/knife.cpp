// #include <sstream> // std::stringstream
#include "knife.h"

using namespace std;

Knife::Knife(unsigned damage, double sharpness) : Weapon(damage), sharpness(sharpness) {}

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

string Knife::toString() const
{
	return "Knife";
	// Múlt héten így volt:
	/*stringstream ss;
	ss << "Weapon<|Knife; damage can be caused when stabbing=" << sharpness*damage << "; sharpness=" << sharpness;
	return ss.str();*/
}