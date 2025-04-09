#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string name, unsigned health, unsigned maxWeaponsCount, Weapon* weapon): name(name), health(health), weaponsCount(0), maxWeaponsCount(maxWeaponsCount), weapons(nullptr), selectedWeaponIndex(0)
{
	// 1. A paraméterül megkapott fegyvert felvesszük
	equipWeapon(weapon);
}

Player::~Player()
{
	// 1. Felszabadítjuk a heterogén kollekciót
	delete[] weapons;

	// 2. Mivel két embernél lehet egyszerre ugyanaz a fegyver, ki kell védenünk a dupla felszabadítást.
	weapons = nullptr;
}

string Player::getName() const
{
	// 1. Visszaadjuk a nevet
	return name;
}

void Player::setName(string name)
{
	// 1. Beállítjuk a nevet
	this->name = name;
}

unsigned Player::getWeaponsCount() const
{
	// 1. Visszaadjuk nálunk lévő fegyverek számát
	return weaponsCount;
}

Weapon* Player::getSelectedWeapon() const
{
	// 1. Ha van nálunk fegyver, visszaadjuk
	if (weaponsCount)
		return weapons[selectedWeaponIndex];

	// 2. Különben nullptr-ral térünk vissza
	return nullptr;
}

unsigned Player::getHealth() const
{
	// 1. Visszatérünk a tárolt életerővel
	return health;
}

bool Player::equipWeapon(Weapon* weapon)
{
	// 1. Nem tud fegyvert felvenni, ha
	//     a) nincs életben
	//     b) nullptr-t kapott paraméterként
	//     c) túl sok fegyver van nála
	if (!isAlive() || !weapon || weaponsCount==maxWeaponsCount)
		return false;

	// 2. Ha már nála van az adott fegyver, ne vegye fel megunsigned
	for (unsigned i = 0; i < weaponsCount; i++)
		if (weapons[i] == weapon) {
			selectedWeaponIndex = i;
			return false;
		}

	// 3. Eggyel nagyobb helyet foglalunk az új fegyvernek
	Weapon** tempWeapons = new Weapon*[weaponsCount + 1];

	// 4. A meglévő fegyvereket átmásoljuk az ideiglenes helyre
	for (unsigned i = 0; i < weaponsCount; i++)
		tempWeapons[i] = weapons[i];

	// 5. Az utolsó helyre bepakoljuk a tárolandó fegyvert
	tempWeapons[weaponsCount++] = weapon;

	// 6. Felszabadítjuk a régi tömböt
	delete[] weapons;

	// 7. Beállítjuk az új tömböt
	weapons = tempWeapons;

	// 8. Az új fegyver lesz a kiválasztott
	selectedWeaponIndex = weaponsCount - 1;

	// 9. Minden művelet sikeres volt, igazzal térünk vissza
	return true;
}

bool Player::dropSelected()
{
	// 1. Nem tudjuk eldobni a fegyvert, ha
	//    a) meghaltunk
	//    b) nincs nálunk
	if (!isAlive() || !weaponsCount)
		return false;

	// 2. Eldobjuk (felszabadítjuk) a kiválasztott fegyvert
	delete weapons[selectedWeaponIndex];

	// 3. Ideigneles Weapon** tömb, ami nem mutat sehova
	Weapon** tempWeapons = nullptr;

	// 4. Ha a kiválasztott fegyver eldobása után marad még nálunk fegyver, a maradékot meg kell tartanunk
	if (weaponsCount - 1) {

		// 4.1.1. Ideiglenes tömböt eggyel kisebb méretű tömbre irányítjuk
		tempWeapons = new Weapon*[weaponsCount-1];

		// 4.1.2. Átmásolunk mindent, ami nem a régi fegyver
		for (unsigned i = 0, j = 0; i < weaponsCount + 1; i++)
			if (i != selectedWeaponIndex)
				tempWeapons[j++] = weapons[i];
		
	}

	// 5. A lista elején lévő fegyverre mutatuk (0).
	//    Akkor is nullára mutatunk, ha nincs fegyverünk, mert úgy is csak akkor fogjuk olvasni, ha a weaponsCount>0.
	selectedWeaponIndex = 0;
	
	// 6. Csökkentjük a fegyverek számát
	weaponsCount--;

	// 7. Eldobjuk a fegyvereket tároló régi tömböt
	delete[] weapons;

	// 8. Beállítjuk az tömbre
	weapons = tempWeapons;

	// 9. Minden művelet sikerült, igazzal térünk vissza
	return true;
}

bool Player::switchToNextWeapon()
{
	// 1. Kilépünk, ha
	//    a) már nem élünk
	//    b) nincs nálunk fegyver
	if (!isAlive() || !weaponsCount)
		return false;

	// 2. Ha a lista végén vagyunk, ugrunk az elejére
	if (selectedWeaponIndex == weaponsCount - 1) {
		selectedWeaponIndex = 0;
		return false;
	}

	// 3. Különben ugrunk a sorban következőre
	selectedWeaponIndex++;

	// 4. Minden sikerült, igazzal térünk vissza
	return true;
}

bool Player::switchToPreviousWeapon()
{
	// 1. Kilépünk, ha
	//    a) már nem élünk
	//    b) nincs nálunk fegyver
	if (!isAlive() || !weaponsCount)
		return false;

	// 2. Ha a lista elején vagyunk, ugrunk a végére
	if (!selectedWeaponIndex) {
		selectedWeaponIndex = weaponsCount-1;
		return false;
	}

	// 3. Különben ugrunk a sorban az előzőre
	selectedWeaponIndex--;

	// 4. Minden sikerült, igazzal térünk vissza
	return true;
}


bool Player::takeDamage(unsigned damage)
{
	// 1. Ha már nem élünk, sebződni se tudunk
	if (!isAlive())
		return false;

	// 2. Ha még tudunk sebződni, sebződünk
	if (health >= damage)
		health -= damage;
	else
		// 3. Halálos csapás esetén nem lesz negatív életerőnk
		health = 0;

	// 4. A játékos sebződött, igazzal térünk vissza
	return true;
}

bool Player::attack(Player& enemy) const
{
	// 1. Nem tudunk támadni, ha
	//    a) már nem élünk
	//    b) nincs fegyverünk
	//if (???)
	//	return false;

	// 2. Eltároljuk, hogy az enemy élt-e még a támadás elején
	//bool isEnemyAliveBeforeAttack = ...

	// 3. Megsebezzük az enemy-t
	//TODO

	// 4. Ha élt az elején, de a végén nem, végzetes csapást mértünk rá
	if (isEnemyAliveBeforeAttack && !enemy.isAlive())
		cout << name << " killed " << enemy.getName() << " with a(n) " << getSelectedWeapon() << endl;

	// 5. Meg tudtuk támadni a másik játékos, igazzal térünk vissza
	return true;
}

bool Player::isAlive() const
{
	// 1. Még él, ha az életereje nagyobb, munsigned nulla
	return health > 0;
}

ostream& operator<<(ostream& os, const Player& right)
{
	// 1. A kimenet legyen ehhez hasonló: <Játékos neve> is [not] alive; health: <szám>; has <fegyverek száma> weapon(s); <selected no weapon|fegyver kiírása>
	os << right.getName() << " is" << (right.isAlive() ? "" : " not") << " alive; health: " << right.getHealth() << "; has " << right.getWeaponsCount() << " weapon(s); selected " << right.getSelectedWeapon();
	return os;
}
