#include <iostream>
#include "display.h"
#include "printer.h"

using namespace std;

int main()
{
	const unsigned maxEquipment = 4;
	
	//Itt hozzunk létre 4 eszközt, az alábbi kimenetek meghatározzák a paramétereiket.
	//Heterogén kollekcióban akarjuk őket tárolni (közös tömbben)

	Equipment* equipment[maxEquipment];
	equipment[0] = new Equipment(1, 200);
	equipment[1] = new Printer(2, 12000, 12000);
	equipment[2] = new Display(3, 2000, 6);
	equipment[3] = new Printer(4, 312000, 51000);


	/************************Elvárt kimenet**************************\
	 Serial Number:1 Price:200 HUF
	 Serial Number:2 Price:12000 HUF Cartridge Price (Printer):12000
	 Serial Number:3 Price:2000 HUF Age (Display): 6
	 Serial Number:4 Price:312000 HUF Cartridge Price (Printer):51000
	\****************************************************************/
	for (int i = 0; i < maxEquipment; i++)
	{
		//Itt ki kell írnunk mindegyiknek az adatát
		equipment[i]->print();
		cout << endl;
		delete equipment[i];
	}

	getchar();
	return 0;
}