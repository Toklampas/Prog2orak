#include "Vector.h"

using namespace std;

void vectorTest()
{
	Vector v1;

	// Insert tesztelése
	for (int i = 1; i < 10; i++)
		v1.insert(i, i);
	

	// A kiírás (operator<<) és az at() függvény tesztelése
	cout << v1 << endl;
	// Elvárt kimenet: 0 1 2 3 4 5 6 7 8 9

	// Másoló konstruktor
	Vector v2(v1); // Lehetne: Vector v2=v1;

	// operator=
	Vector v3;
	v3 = v2;

	// Megváltoztatjuk v1-t (erase tesztelése)
	v1.erase(0);
	
	// v1.erase(9); // false

	cout << endl << v1 << endl << v2 << endl << v3 << endl;
	// Elvárt kimenet:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9

	v2.insert(0, -1);
	cout << endl << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10, -1);
	cout << endl << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12, -1);
	cout << endl << v2 << endl;
	// Elvárt kiment: -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15, -1);
	cout << endl << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	v2[15] = -2;
	cout << endl << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2
}
