/* Levendovszky Tihamér 2008 */

#include <iostream>
#include <exception> // Ebben van az exception ősosztály
#include <string>
using namespace std;

// A következo példa megmutatja, hogy kell saját kivételt készíteni.
class null_pointer_exception : public exception
{
	// Itt hozzáadunk az adott kivételre jellemző plusz adatot az alaposztályhoz.
	int errorCode;
	string errorMessage; // Ez egy beépített string osztály, a sajátunkat is használhatjuk...

public:
	// Miért a konstruktorban állítjuk össze a hibaüzenetet?
	null_pointer_exception(const char * reason, int errorCode = 0)
	{
		this->errorCode = errorCode;
		errorMessage += reason;
	}

	const char* what() const throw()
	{
		// Ez  függvény egy const char *-got ad vissza a stringre
		return errorMessage.c_str();
	}

	int getErrorCode()const { return errorCode; }
	// A destruktorra azért van szükség, mert a fordító által generált destruktornak nincs kivételspecifikációja,
	// ami a throw(...) kivételspecifikációval egyezik meg, vagyis a virtuális destruktor felülírásakor
	// enyhébb kivételspecifikációt adtunk meg, ami hiba.
	~null_pointer_exception() throw() {}
};

// Egy "kamu" osztály a verem visszagörgetésének szemléltetésére
class dummy
{
	int value;
public:
	dummy(int value) { this->value = value; }
	~dummy() { cout << "Dummy " << value << " has been destructed :-(." << endl; }
};

void print(const char * str)
{
	// Vajon tényleg meghívódik a destruktor, ha kivétel történik?
	dummy d1(1);

	// A konstruktor konverziós funkcióját használjuk egy ideiglenes objektum
	// létrehozására, amit eldobunk, lemásolódik, és majd referencia szerint átadjuk
	if (str == nullptr)
		throw null_pointer_exception("String must be supplied", -1);

	// Kiírjuk a stringet
	cout << str << endl;
}

void start()
{
	// Vajon tényleg meghívódik a destruktor, ha kivétel történik?
	dummy d2(2);

	// A függvény hívása közben kivétel keletkezhet.
	try
	{
		// Bizony, ez kivétel lesz...
		print(nullptr);
	}
	// Itt csak a null_pointer_exceptiont kezeljük, a többit nem
	catch (const null_pointer_exception &e)
	{
		cout << e.what() << endl;

		// Ha nem általánosabb osztályként kapjuk el, az összes publikus tagjához hozzáférünk.
		if (e.getErrorCode() != -1)
		{
			// Ha nem -1 a hibakód, ez a catch blokk nem kezeli, hanem továbbdobja egy paraméter nélküli throw segítségével...
			throw;
		}
	}
}

int main()
{
	// Ez a main függvény védekező és mindent elkapó catch blokkhoz tartozó try blokkja,
	// amit automatikusan, gondolkodás nélkül ideírunk.
	try
	{
		// Ide jön a program érdemi része. Most itt meghívjuk a mórickapéldánkat...
		start();
	}
	// Minden "tisztességes" kivételt elkapunk
	catch (const exception& e)
	{
		cerr << "Application error: " << e.what() << endl;
	}
	// Felkészülünk minden eshetőségre, és mentjük, ami menthető...
	catch (...)
	{
		cerr << "Unexpected error. Please restart the program." << endl;
	}

	return 0;
}
