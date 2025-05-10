/* Levendovszky Tihamér 2009 */

#include <iostream>
#include <exception> // Ebben van az exception ősosztály
#include <string>
using namespace std;

class null_pointer_exception : public exception
{
	// Itt hozzáadunk az adott kivételre jellemző plusz adatot az alaposztályhoz.
	int errorCode;
	string errorMessage; // Ez egy beépített string ősztály, a sajátunkat is használhatjuk...

public:
	// Miért a konstruktorban állítjuk össze a hibaüzenetet?
	null_pointer_exception(const char * reason, int errorCode = 0)
	{
		this->errorCode = errorCode;
		errorMessage += reason;
	}

	const char* what()const throw()
	{
		// Ez  függvény egy const char *-got ad vissza a stringre
		return errorMessage.c_str();
	}

	int getErrorCode()const { return errorCode; }

	// A destruktorra azért van szükség, mert a fordító által generált destruktornak nincs kivételspecifikációja,
	// ami a throw(...) kivétlspecifikációval egyezik meg, vagyis a virtuális destruktor felülírásakor
	// enyhébb kivételspecifikációt adtunk meg, ami hiba.
	virtual ~null_pointer_exception()throw() {}
};

int main()
{
	try
	{
		throw null_pointer_exception("Valid pointer must be provided.", -2);
	}

	catch (const null_pointer_exception& e)
	{
		cerr << "Null pointer error: " << e.what() << endl;
	}

	catch (const exception& e)
	{
		cerr << "Application error: " << e.what() << endl;
	}

	catch (...)
	{
		cerr << "Unexpected error. Please restart the program." << endl;
	}
	return 0;
}
