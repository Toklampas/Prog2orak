#include "vector.h"
using namespace std;

int main()
{
	Vector v1;
	// insert tesztelése
	for (int i = 1; i<10; i++)
		v1.insert(i, i);
	
	// A kiírás (operator<<) és az at() függvény tesztelése
	cout << v1 << endl;
	// Helyes eredmény: 0 1 2 3 4 5 6 7 8 9

	// Másoló konstruktor tesztelése
	Vector v2(v1); // Lehetne: Vector v2=v1;
	
	// operator= tesztelése
	Vector v3;
	v3 = v2;

	// erase tesztelése (megváltoztatjuk v1-t)
	v1.erase(0);
	// v1.erase(9); // Ennek assertelni kell
	cout << endl << v1 << endl << v2 << endl << v3 << endl;
	// Helyes eredmény:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	
	// insert tesztelése
	v2.insert(0, -1);
	cout << v2 << endl;
	// Helyes eredmény: -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10, -1);
	cout << v2 << endl;
	// Helyes eredmény: -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12, -1);
	cout << v2 << endl;
	// Helyes eredmény: -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15, -1);
	cout << v2 << endl;
	// Helyes eredmény: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	// operator[] tesztelése
	v2[15] = -2;
	cout << v2 << endl;
	// Helyes eredmény: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2
	// v2[16]=3; // Ennek assertelni kell

	// operator*= tesztelése
	v2 *= 10;
	cout << v2 << endl;
	// Helyes eredmény: -10 0 10 20 30 40 50 60 70 80 -10 90 -10 0 0 -20

	// rendezés tesztelése
	v2.sort();
	cout << v2 << endl;
	// Helyes eredmény: -20 -10 -10 -10 0 0 0 10 20 30 40 50 60 70 80 90

	v2.sort(Sorters::descend);
	cout << v2 << endl;
	// Helyes eredmény: 80 70 60 50 40 30 20 10 0 0 0 -10 -10 -10 -20

	// tömb feltöltés operátor túlterheléssel
	Vector v4(5);
	cin >> v4;
	cout << endl << v4 << endl;
	return 0;
}