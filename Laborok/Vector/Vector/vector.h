#pragma once
#include <iostream>

namespace Sorters {
	bool ascend(const int&, const int&);
	bool descend(const int&, const int&);
}

// Egy dinamikus tömb osztály
class Vector
{
	// A tömb mérete
	unsigned elementNum;

	// A tömb maximális mérete; alapértelmezetten 20
	unsigned maxElementsNum;

	// A dinamikus adatokra mutató pointer
	int *pData;
	
	// Diagnosztikai célú globális kiiratóoperátor
	friend std::ostream& operator<<(std::ostream&, const Vector&);

	// Tömbfeltöltés operátor túlterheléssel
	friend std::istream& operator>>(std::istream&, Vector&);
public:
	// Konstruktorok, destruktor
	Vector(unsigned=20);
	Vector(const Vector&);  //egyenlo operatort csinalunk es meghivjuk a masolo konstruktoron belul igy egyszerubb
	~Vector();

	// Visszatér a tömb méretével.
	unsigned size() const;

	// Visszatér a tömb maximális méretével.
	unsigned getMaxElementsNum() const;

	// Törli a tömböt.
	void clear();
	
	// Törli a megadott indexű elemet. A 0 és size()-1 közötti indexek érvényesek.
	bool erase(unsigned);

	// Visszatér a megadott indexű elemmel, amely módosítható is egyben.
	// A 0 és size()-1 közötti indexek érvényesek.
	int& at(unsigned);

	// Visszatér a megadott indexű elemmel, amely csak olvasható.
	// A 0 és size()-1 közötti indexek érvényesek. Az int típus esetén nem kellene
	// const referencia (mert olcsó művelet a beépített típusú
	// változók másolása), de saját típus esetén igen.
	const int& at(unsigned) const;

	// Beszúr egy elemet a megadott indexű helyre.
	// Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét,
	// és a szükséges új helyeket nullákkal tölti fel.
	bool insert(unsigned, int);

	void sort(bool(*)(const int&, const int&) = Sorters::ascend);

	// operator=
	Vector& operator=(const Vector&);

	// Két operator[]. Az at() tagfüggvény operator formában is.
	int& operator[](unsigned);
	const int& operator[](unsigned) const;

	// Minden elem megszorzása a jobb oldali operandussal.
	void operator*=(unsigned);

	// A jobb oldali operandus hozzáadása minden elemhez.
	void operator+=(unsigned);
};

// Diagnosztikai célú kiiratás
std::ostream& operator<<(std::ostream&, const Vector&);

// Tömbfeltöltés operátor túlterheléssel
std::istream& operator>>(std::istream&, Vector&);