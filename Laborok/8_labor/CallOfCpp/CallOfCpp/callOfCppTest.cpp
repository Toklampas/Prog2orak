#include <iostream>
#include "weapon.h"
#include "knife.h"
#include "pistol.h"
#include "railgun.h"

using namespace std;

int main() {

	Weapon excalibur(100);
	Knife knife;
	Pistol pistol;
	Railgun railgun;

	cout << excalibur.toString() << endl;
	cout << knife.toString() << endl;
	cout << pistol.toString() << endl;
	cout << railgun.toString() << endl;

	cout << endl;

	cout << "Damage caused with excalibur: " << excalibur.use() << endl;
	cout << "Damage caused with knife: " << knife.use() << endl;
	cout << "Damage caused with pistol: " << pistol.use() << endl;
	cout << "Damage caused with railgun: " << railgun.use() << endl;

	knife.sharpen();
	pistol.reload();
	railgun.recharge();

	cout << endl;

	cout << excalibur.toString() << endl;
	cout << knife.toString() << endl;
	cout << pistol.toString() << endl;
	cout << railgun.toString() << endl;

	return 0;
}
