#include <vector>
#include <iostream>
#include "element_not_found.hpp"

using namespace std;

vector<char>  v = { 'h', 'a', 'r', 'r', 'y' };

char f1(unsigned pos) {
	// Dobj kivételt, ha túl kicsi, vagy túl nagy indexet adott meg!
	if (pos >= v.size())
		throw std::out_of_range("Index out of range");
	return v[pos];
}

vector<int*> f2() {
	vector<int*> pInts;
	// A kivételt a new dobja.
	try
	{
		for (int i = 0; i < 10000000; pInts.push_back(new int[10000]), i++);
	}
	catch (const std::bad_alloc&)
	{
		for (int* ptr : pInts)
			delete[] ptr;
		throw;
	}
	return pInts;
}

char f3() {
	vector<char>::iterator it = find(v.begin(), v.end(), 'g');
	// Dobj saját kivételt (element_not_found<char>('g')), ha nem található a keresett elem.
	if (it == v.end()) {
		throw element_not_found<char>('g');
	}
	return *it;
}

void f4() {
	// Dobj kivételt, ha az 1. karakter már 'H'.
	if (v[0] == 'h') {
		throw std::logic_error("First character is already 'h'");
	}
	v[4] = 'h';
}

extern "C" char bonus(unsigned pos) {
	// - Ez egy C függvény, tehát itt nem tudsz kivételt használni.
	// - Milyen más megoldást ismersz, ami nem hagyományos kiíratás?
	// - Mire kell vigyázni vele kapcsolatban?
	if (pos >= v.size()) {
		return '\0';
	}
	return v[pos];
}

int main() {
	// A)
	try
	{
		f1(6);
	}
	catch (const std::out_of_range& ex)
	{
		cout << "f1 exception: " << ex.what() << endl;
	}

	// B)
	try
	{
		vector<int*> pInts;
		pInts = f2();
		for (vector<int*>::iterator it = pInts.begin(); it != pInts.end(); delete *it, ++it);
	}
	catch (const std::bad_alloc& ex)
	{
		cout << "f2 exception: " << ex.what() << endl;
	}

	// C)
	try
	{
		f3();
	}
	catch (const element_not_found<char>& ex)
	{
		cout << "f3 exception: " << ex.what() << " - Element: " << ex.get_element() << endl;
	}

	// D)
	try
	{
		f4();
	}
	catch (const std::logic_error& ex)
	{
		cout << "f4 exception: " << ex.what() << endl;
	}
	
	// E) - Szorgalmi.
	char result = bonus(6);
	if (result == '\0')
		cout << "bonus error: Invalid index provided" << endl;
	else 
		cout << "bonus result: " << result << endl;

	std::cin.get();
	return 0;
}