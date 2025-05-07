/* Levendovszky Tihamér 2007 */

#include <iostream>
#include <exception> // Ebben van az exception ősosztály
using namespace std;

int main()
{
	try
	{
		// 1.1. Próbáld ki mi történik akkor, ha nem dobódik kivétel egy try blokkban!
		// Ez azt jelenti, hogy minden rendben volt.

		// 1.2. Először dobj egy osztálykönyvtárbeli kivételt. Ez minden "tisztességes"
		// kivétel ősosztálya, a kód mutatja az alapvető muködését: megadsz egy hibaüzenetet
		// a konstruktorban, amit majd a what() tagfüggvénnyel lehet kiíratni. Ehhez távolítsd
		// el a következő sor elől a megjegyzés jelet!

		// throw exception();

		// 1.3. Tedd újra megjegyzéssé az előző sort. Másodikként próbáld ki a "tisztességtelen"
		// kivételdobást. Ez azt jelenti, hogy nem az exception osztályból származóból dobunk, hanem
		// egy valamit egy beépített típusból. Ehhez távolítsd el a következő sor elől a megjegyzés jelet!

		// throw "Baj van!";

		// Ide rakj egy break pointot
		cout << "Checkpoint 1 - no error" << endl;
	}
	catch (const exception& e)
	{
		cerr << "Application error: " << e.what() << endl;
	}
	catch (...)
	{
		// Itt nem tudunk semmit sem kiírni, hiszen nem kapjuk meg a paramétert. Fogalmunk
		// sincs a tényleges hibáról. Azért írtuk ide, hogy mi lépjünk ki az alkalmazásból,
		// ne az operációs rendszer közölje a hibát a felhasználóval.

		// Az egyszerű típusok általában itt landolnak, mert nem írunk mindegyikre
		// catch blokkot (pl. catch(const char* e), catch (int e), stb.), mert az sok kód,
		// nem szép. Ezért származtassunk mindig az exception osztályból.

		cerr << "Unexpected error. Please restart the program." << endl;
	}


	// Ide teszünk egy break pointot (Itt mindkét esetben - ha volt hiba, ha nem átmegy a vezérlés)
	cout << "Checkpoint 2 - both cases" << endl;

	return 0;
}


