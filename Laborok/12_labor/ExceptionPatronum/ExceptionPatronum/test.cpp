#include <vector>
#include "element_not_found.hpp"

using namespace std;

vector<char>  v = { 'h', 'a', 'r', 'r', 'y' };

char f1(unsigned pos) {
	// Dobj kivételt, ha túl kicsi, vagy túl nagy indexet adott meg!
	return v[pos];
}

vector<int*> f2() {
	vector<int*> pInts;
	// A kivételt a new dobja.
	for (int i = 0; i < 10000000; pInts.push_back(new int[10000]), i++);
	return pInts;
}

char f3() {
	vector<char>::iterator it = find(v.begin(), v.end(), 'g');
	// Dobj saját kivételt (element_not_found<char>('g')), ha nem található a keresett elem.
	return *it;
}

void f4() {
	// Dobj kivételt, ha az 1. karakter már 'H'.
	v[4] = 'H';
}

extern "C" char bonus(unsigned pos) {
	// - Ez egy C függvény, tehát itt nem tudsz kivételt használni.
	// - Milyen más megoldást ismersz, ami nem hagyományos kiíratás?
	// - Mire kell vigyázni vele kapcsolatban?
	return v[pos];
}

int main() {
	// A)
	f1(6);

	// B)
	vector<int*> pInts;
	pInts = f2();
	for (vector<int*>::iterator it = pInts.begin(); it != pInts.end(); delete *it, ++it);

	// C)
	f3();


	// D)
	f4();
	
	// E) - Szorgalmi.
	bonus(6);

	cin.get();
}