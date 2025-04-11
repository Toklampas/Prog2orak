#include "VendingMachine.h"
#include <string>

int main()
{
	// kóla definiálása
	std::string Cola("Coca-Cola");

	// TODO másfajta ital(ok) definiálása
	std::string Fanta("Fanta");
	std::string MD("MD");


	// automata létrehozása
	VendingMachine coldDrinkMachine;	

	// feltöltés 5 Coca-colával
	coldDrinkMachine.refill(Cola, 5);
	coldDrinkMachine.refill(Fanta, 2);
	coldDrinkMachine.refill(MD, 10);

	// ellenőrzés
	coldDrinkMachine.print();

	// TODO vásárlás és másoló konstruktor kipróbálása, több automata létrehozása
	VendingMachine hotDrinkMachine(coldDrinkMachine);

	hotDrinkMachine.buy(5);

	hotDrinkMachine.print();
	
}

