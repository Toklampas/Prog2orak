#pragma once
#include <iostream>

using namespace std;

class Malacpersely
{
	int penztartalom;
public:
	Malacpersely(int penz=0) : penztartalom(penz) {}
	void bedob(int penz);
	void atont(Malacpersely& masik);
	int ertek() const { return penztartalom; }

	Malacpersely operator+(int penz) const;
	Malacpersely& operator+=(int penz);
	Malacpersely operator+(Malacpersely masik) const;
	Malacpersely& operator+=(Malacpersely masik);

};

ostream& operator<<(ostream& os, const penz& dt)
{
}