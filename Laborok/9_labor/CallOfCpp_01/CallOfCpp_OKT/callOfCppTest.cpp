#include <iostream>
#include "weapon.h"
#include "knife.h"
#include "pistol.h"
#include "railgun.h"

using namespace std;

int main() {
	//Tárold a fenti fegyvereket közös tömbben (hetereogén kollekció)
	const unsigned maxWeapons = 3;

	Weapon* weapons[maxWeapons];

	weapons[0] = new Knife;
	weapons[1] = new Pistol;
	weapons[2] = new Railgun;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekció felhasználásával!
	for (int i = 0; i < maxWeapons; i++) {
		cout << weapons[i]->toString() << endl;
	}

	cout << endl;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	for (int i = 0; i < maxWeapons; i++) {
		cout << "Damage caused with weapon " << i + 1 << ": " << weapons[i]->use() << endl;
	}

	dynamic_cast<Knife*>(weapons[0])->sharpen();
	dynamic_cast<Pistol*>(weapons[1])->reload();
	dynamic_cast<Railgun*>(weapons[2])->recharge();


	cout << endl;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	for (int i = 0; i < maxWeapons; i++) {
		cout << weapons[i]->toString() << endl;
	}

	for (int i = 0; i < maxWeapons; i++) {
		delete weapons[i];
	}

	return 0;
}
