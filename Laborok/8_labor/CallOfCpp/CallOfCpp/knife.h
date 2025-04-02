#pragma once
#include "weapon.h"

using namespace std;

class Knife : public Weapon {
	double sharpness;
public:
	Knife(unsigned damage = 30, double psharpness = 0.8);

	void sharpen();
	unsigned use();
	double getSharpness() const;
	void setSharpness(double psharpness);
	string toString();
};