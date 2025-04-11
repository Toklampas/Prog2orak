#include "VendingMachine.h"
#include <cstdio>

// alapértelmezett konstruktor
// kezdetben üres a gép
VendingMachine::VendingMachine()
{
	drinkNumber = 0;
	drinks = nullptr;
}

// TODO
// Figyelj, hogy mély másolatot készíts! Bitről bitre másolás nem lesz jó!
// Tesztelheted, hogy a program lefutása végén lesz-e heap corruption.
// másoló konstruktor
VendingMachine::VendingMachine(const VendingMachine & other)
{
	drinkNumber = other.drinkNumber;
	drinks = nullptr;
	if (drinkNumber > 0)
	{
		drinks = new std::string[drinkNumber];
		for (int i = 0; i < drinkNumber; ++i)
		{
			drinks[i] = other.drinks[i];
		}
	}
}

int VendingMachine::getDrinkNumber()
{
	return drinkNumber;
}

VendingMachine::~VendingMachine()
{
	// fel kell szabadítani az italoknak lefoglalt memóriaterületet
	delete[] drinks;
}

// első ital kivétele
// visszatér a nevével
std::string VendingMachine::removeOne()
{
	// ellenőrzés, hogy van-e még üdítő az automatában
	if (drinkNumber <= 0)
		return "Empty";

	// visszatérési érték, első elem
	std::string value = drinks[0];

	// kisebb méretű tömb lefoglalása
	std::string* tmp;
	tmp = new std::string[drinkNumber - 1];

	// első utáni elemek átmásolása
	for (int i = 1; i < drinkNumber; i++)
		tmp[i-1] = drinks[i];

	// darabszám csökkentése
	drinkNumber = drinkNumber - 1;

	// régi tömb felszabadítása
	delete[] drinks;

	// új tömb beírása az osztályba
	drinks = tmp;

	// visszatérés
	return value;
}

// vásárlás
// egyszerre több italt is lehet vásárolni, alapértelmezetten 1
// ha többet vennénk, mint amennyi készleten van, hamissal tér vissza, egyébként igazzal
// sikeres vásárlás esetén csökkenteni kell a darabszámot, és törölni az elemeket
bool VendingMachine::buy(int num)
{
	if (num > drinkNumber)
		return false;
	for (int i = 0; i < num; i++)
	{
		printf("Vasarolt ital: %s\n", removeOne().c_str());
	}
	return true;

}
// IMSC: itt találtuk meg (printf függvény itt)
// lezáró nulla kéne a stringek végére hogy kompatibilisek legyenek
// nem hatékony, mert több memóriát használ. Lehetne c++-os kiirást használni helyette, ami kezeli a c++-os stringet.




// TODO
// automata feltöltése
// meg kell adni az ital nevét, és hogy mennyit rakunk belőle a gépbe
bool VendingMachine::refill(std::string pName, int pQty)
{
	// csak pozitív értékkel működjön
	if (pQty <= 0)
		return false;
	//nagyobb tömb lefoglalása
	std::string* tmp;
	tmp = new std::string[drinkNumber + pQty];
	// meglévő elemek átmásolása
	for (int i = 0; i < drinkNumber; i++)
		tmp[i] = drinks[i];
	// új elemek betöltése
	for (int i = 0; i < pQty; i++)
		tmp[i] = pName;
		
	// darabszám felülírása
	drinkNumber = drinkNumber + pQty;
	// régi tömb törlése
	delete[] drinks;
	// új tömb átírása
	drinks = tmp;
	return true;
}

// készlet kiírása
void VendingMachine::print()
{
	printf("Keszlet: %d\n", drinkNumber);
	for (int i = 0; i < drinkNumber; i++)
		printf("%s\n", drinks[i].c_str());
	printf("---Lista vege---\n\n");
}


