#include <iostream>
#include <string>
#include "vector.hpp"
#include "state.hpp"
#include "finiteAutomaton.hpp"

using namespace std;

// Kutya reprezentálása. Az egyszerűség kedvéért struct,
// illetve egy kis emlékeztető, hogy még ez is létezik.
struct Dog
{
	string name; // A kutya neve publikus.

	// Alapértelmezett és nevet váró konstruktor egyszerre.
	// Alapértelmezett nélkül nem lehetne Vector-ban tárolni.
	Dog(string name = string()) : name(name) {}

	// Szükséges az input elemek összehasonlításakor.
	bool operator==(const Dog& other) const {
		return name == other.name;
	}

	// Megjegyzés: most megelégszünk az alapértelmezett operator=-vel.
};

void finiteAutomatonTest()
{
	// Állapotok definiálása. Az állapotainknak string label-je van.
	State<string> anyDog = State<string>("AnyDog", false);
	State<string> mackoAppeared = State<string>("MackoAppeared", false);
	State<string> neroAppeared = State<string>("NeroAppeared", false);
	State<string> rexAppeared = State<string>("RexAppeared", true); // Csak a rexAppeared elfogadó!

	// Az automatánk string labellel rendelkező állapotokkal, valamint Dog-okból álló inputtal dolgozik.
	FiniteAutomaton<string, Dog> fa(anyDog); // Az kezdőállapot az anyDog.
	fa.addState(mackoAppeared); // Hozzáadjuk a többi állapotot.
	fa.addState(neroAppeared);
	fa.addState(rexAppeared);

	// A bemenetünk ennek a három kutyának a véges hosszú ismétléses variációja lesz.
	Dog macko = Dog("Macko");
	Dog nero = Dog("Nero");
	Dog rex = Dog("Rex");

	// Az anyDoghoz tartozó állapotátmeneteket definiáljuk a feladatsorban található állapotdiagrammnak megfelelően.
	// Az első három jelentése: ha anyDog állapotban vagyunk és macko-t olvasunk,
	// menjünk át a mackoAppeared állapotba. Minden más esetben maradjunk anyDog-ban.
	fa.addRule(Rule<string, Dog>(anyDog, macko, mackoAppeared));
	fa.addRule(Rule<string, Dog>(anyDog, nero, anyDog));
	fa.addRule(Rule<string, Dog>(anyDog, rex, anyDog));

	// Ugyanígy teszünk a mackoAppeared állapottal is.
	fa.addRule(Rule<string, Dog>(mackoAppeared, macko, mackoAppeared));
	fa.addRule(Rule<string, Dog>(mackoAppeared, nero, neroAppeared));
	fa.addRule(Rule<string, Dog>(mackoAppeared, rex, anyDog));

	// neroAppeared állapot állapotátmenetei.
	fa.addRule(Rule<string, Dog>(neroAppeared, macko, mackoAppeared));
	fa.addRule(Rule<string, Dog>(neroAppeared, nero, anyDog));
	fa.addRule(Rule<string, Dog>(neroAppeared, rex, rexAppeared));

	// rexAppeared állapot állapotátmenetei.
	fa.addRule(Rule<string, Dog>(rexAppeared, macko, rexAppeared));
	fa.addRule(Rule<string, Dog>(rexAppeared, nero, rexAppeared));
	fa.addRule(Rule<string, Dog>(rexAppeared, rex, rexAppeared));

	// A Dog-okból álló bemeneti szekvenciánk.
	Vector<Dog> input;
	
	// Ugrálunk az anyDog és a mackoAppeared között, de még nem ismeri fel az automata
	// a részszekvenciát (macko, nero, rex).
	input.insert(0, rex);
	input.insert(1, rex);
	input.insert(2, nero);
	input.insert(3, macko);
	input.insert(4, rex);
	input.insert(5, macko);
	
	// Most fogjuk felismerni az automata által felismerhető részszekvenciát.
	input.insert(6, macko);
	input.insert(7, nero);
	input.insert(8, rex);

	// Maradunk rexAppearedben, mert csak az számít, hogy megtaláltuk a részszekvenciát.
	input.insert(9, nero);
	input.insert(10, macko);
	input.insert(11, rex);

	// Kiírjuk, hogy megtalálta-e a szekvenciát az automata vagy sem.
	// boolalpha: iostreamből jön; a bool értéket szövegesen fogja kiírni utána.
	cout << "Result of the Finite Automata is " << boolalpha << fa.run(input);

	// Elvárt kimenet:
	/*AnyDog
	AnyDog
	AnyDog
	AnyDog
	MackoAppeared
	AnyDog
	MackoAppeared
	MackoAppeared
	NeroAppeared
	RexAppeared
	RexAppeared
	RexAppeared
	RexAppeared
	Result of the Finite Automata is true*/
}
