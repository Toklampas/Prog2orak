#pragma once

#include <iostream>

// Egy dinamikus tömb osztály.
class Vector
{
	// A tömb mérete.
	unsigned elementNum;

	// Az adatokra mutató pointer.
	int *pData;

	// Diagnosztikai célú globális kiiratóoperátor.
	friend std::ostream& operator<<(std::ostream&, const Vector&);

public:
	// Konstruktorok, destruktor.
	Vector();
	Vector(const Vector& other);
	~Vector();

	// Visszatér a tömb méretével. 
	unsigned  size() const;
	
	// Törli a tömböt.
	void clear();

	// Törli a megadott indexű elemet. A 0 és size()-1 közötti indexek érvényesek.
	// Igazzal tér vissza, ha sikeres a törlés, különben hamissal.
	bool erase(unsigned position);

	// Visszatér a megadott indexu elemmel, amely módosítható is egyben.
	// A 0 és size()-1 közötti indexek érvényesek.
	int& at(unsigned position);

	// Visszatér a megadott indexu elemmel, amely csak olvasható.
	// A 0 és size()-1 közötti indexek érvényesek.
	const int& at(unsigned position) const;

	// Beszúr egy elemet a megadott indexű helyre. 
	// Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét, 
	// és a szükséges új helyeket nullákkal tölti fel.
	bool insert(unsigned position, int element);

	// A bal oldali vektort felülírja a jobb oldalival.
	const Vector& operator=(const Vector& theOther);

	// Két operator[]. Az at() tagfüggvény operator formában is.
	int& operator[](unsigned position);
	const int& operator[](unsigned position) const;
};

// Diagnosztikai célú kiiratás.
std::ostream& operator<<(std::ostream& os, const Vector& v);
