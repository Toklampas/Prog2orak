#pragma once
#include <iostream>
#include "vector.hpp"
#include "state.hpp"
#include "rule.hpp"

// TODO: template
class FiniteAutomaton
{
	// Szóköz nélkül a C++98 fordító shift operátornak értelmezné.
	// Egy Vector, amiben a szabályokat tároljuk.
	Vector< Rule<LABEL_TYPE, INPUT_TYPE> > rules;

	// Egy Vector, amiben a véges automata állapotait tároljuk.
	Vector< State<LABEL_TYPE> > states;

	// Rámutatunk az aktuális állapotra. Konstans, hogy tudjunk mutatni
	// a Rule::getNextState() által visszaadott állapotra.
	const State<LABEL_TYPE>* currentState;
public:
	// Megadjuk a kezdő állapotot konstruktorban.
	FiniteAutomaton(State<LABEL_TYPE>& startState) : currentState(&startState)
	{
		// 1. Hozzáadjuk az állapotokhoz a kezdőállapotot.
		
	}

	// Hozzáadhatunk egy új állapotot.
	// Konstans, hogy át tudjunk adni konstanst.
	void addState(const State<LABEL_TYPE>& state)
	{
		// 1. Beszúrjuk a states-be a paraméterként megkapott state-t.
		
	}

	// Hozzáadhatunk új szabályt.
	// Konstans, hogy át tudjunk adni konstanst.
	void addRule(const Rule<LABEL_TYPE, INPUT_TYPE>& rule)
	{
		// 1. Beszúrjuk a rules-ba a paraméterként megkapott rule-t.
		
	}

	// A paraméterként kapott inputon futtatjuk az véges automatát.
	bool run(const Vector<INPUT_TYPE>& input)
	{
		// 1. Végigmegyünk a bemeneten.
		
		
			// 1.1. Diagnosztikai célból írassuk ki az aktuális állapotot.
			

			// 1.2. Mivel azt is ellenőriznünk kell, hogy van-e egyáltalán illeszkedő (matched) szabály
			// az aktuális állapotra és most következő bemenetre, vegyük úgy alapból, hogy
			// nincs illeszkedés. Ezzel a változóval ellenőrizhető, hogy a véges automata állapotátmenetei
			// hiányosan lettek-e specifikálva vagy sem.
			

			// 1.3. Menjünk végig az összes szabályon, de korábban is megállhatunk,
			// ha már találtunk illeszkedő szabályt.
			
			
				// 1.3.1. Ha van illeszkedés (match) a j. szabállyal:
				
					
					// 1.3.1.1. Az aktuális állapot legyen egyenlő a szabályban tárolt következő lehetséges állapottal.
					

					// 1.3.1.2. Ne felejtsük el feljegyezni, hogy van illeszkedő szabály (1.2.)
					
				
			

			// 1.4. Ha nem volt illeszkedő szabály, tehát a véges automata elakadt, nem tudott továbbmenni, térjünk vissza hamissal.
			
				
		

		// 2. Írassuk ki az aktuális állapotot.
		

		// 3. Térjünk vissza igazzal, ha az aktuális állapot elfogadó volt, különben hamissal.
		
	}
};