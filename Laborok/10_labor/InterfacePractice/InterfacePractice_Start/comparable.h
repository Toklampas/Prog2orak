#pragma once

// Ezt az 1. feladat használhatja, 3.-ban áttérnek a 2. feladat statikus könyvárjára
class Comparable
{
public:
	// Igazzal tér vissza, ha a két Comparable egyenlő (implementáció függő),
	// minden más esetben hamissal.
	virtual bool operator==(const Comparable& other) const = 0;

	// Igazzal tér vissza, ha a bal oldali Comparable kisebb (szintén implementáció függő),
	// mint a jobb oldali (other), minden más esetben hamissal.
	virtual bool operator<(const Comparable& other) const = 0;
};