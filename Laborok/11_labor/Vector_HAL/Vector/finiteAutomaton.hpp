#pragma once
#include <iostream>
#include "vector.hpp"
#include "state.hpp"
#include "rule.hpp"

// TODO: template
template <typename LABEL_TYPE, typename INPUT_TYPE>
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
		states.insert(0, startState);
	}

	// Hozzáadhatunk egy új állapotot.
	// Konstans, hogy át tudjunk adni konstanst.
	void addState(const State<LABEL_TYPE>& state)
	{
		// 1. Beszúrjuk a states-be a paraméterként megkapott state-t.
		states.insert(states.size(), state);
	}

	// Hozzáadhatunk új szabályt.
	// Konstans, hogy át tudjunk adni konstanst.
	void addRule(const Rule<LABEL_TYPE, INPUT_TYPE>& rule)
	{
		// 1. Beszúrjuk a rules-ba a paraméterként megkapott rule-t.
		rules.insert(rules.size(), rule);
	}

	// A paraméterként kapott inputon futtatjuk az véges automatát.
	bool run(const Vector<INPUT_TYPE>& input)
	{
		// 1. Végigmegyünk a bemeneten.
		for (size_t i = 0; i < input.size(); ++i)
		{

			// 1.1. Diagnosztikai célból írassuk ki az aktuális állapotot.
			std::cout << *currentState << std::endl;

			// 1.2. Mivel azt is ellenőriznünk kell, hogy van-e egyáltalán illeszkedő (matched) szabály
			// az aktuális állapotra és most következő bemenetre, vegyük úgy alapból, hogy
			// nincs illeszkedés. Ezzel a változóval ellenőrizhető, hogy a véges automata állapotátmenetei
			// hiányosan lettek-e specifikálva vagy sem.
			bool matched = false;

			// 1.3. Menjünk végig az összes szabályon, de korábban is megállhatunk,
			// ha már találtunk illeszkedő szabályt.
			for (size_t j = 0; j < rules.size(); ++j)
			{

				// 1.3.1. Ha van illeszkedés (match) a j. szabállyal:
				if (rules[j].match(*currentState, input[i]))
				{

					// 1.3.1.1. Az aktuális állapot legyen egyenlő a szabályban tárolt következő lehetséges állapottal.
					currentState = &rules[j].getNextState();

					// 1.3.1.2. Ne felejtsük el feljegyezni, hogy van illeszkedő szabály (1.2.)
					matched = true;
					break;
				}
			}

			// 1.4. Ha nem volt illeszkedő szabály, tehát a véges automata elakadt, nem tudott továbbmenni, térjünk vissza hamissal.
			if (!matched)
				return false;
		}
		

		// 2. Írassuk ki az aktuális állapotot.
		std::cout << *currentState << std::endl;

		// 3. Térjünk vissza igazzal, ha az aktuális állapot elfogadó volt, különben hamissal.
		return currentState->isAccepting();
		
	}
};