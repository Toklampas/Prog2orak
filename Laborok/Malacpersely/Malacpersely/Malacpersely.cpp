#include "Malacpersely.h"

void Malacpersely::bedob(int penz) {
	penztartalom += penz;
}

void Malacpersely::atont(Malacpersely& masik) {
	penztartalom += masik.penztartalom;
	masik.penztartalom = 0;
}

Malacpersely Malacpersely::operator+(int penz) const
{
	return Malacpersely(penztartalom + penz);
}

Malacpersely& Malacpersely::operator+=(int penz)
{
	penztartalom += penz;
	return *this;
}

Malacpersely Malacpersely::operator+(Malacpersely masik) const
{
	return Malacpersely(penztartalom + masik.penztartalom);
}

Malacpersely& Malacpersely::operator+=(Malacpersely masik)
{
	penztartalom += masik.penztartalom;
	masik.penztartalom = 0;
	return *this;
}





