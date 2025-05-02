#pragma once
#include "state.hpp"

// TODO: template
class Rule
{
	// Ha referencia lenne, nem lehetne operator=-t írni úgy, hogy a Vector-ban ne pointereket tároljunk.
	// Ami ugyan jó megoldás lenne, csak kicsit bonyolultabb.
	// Konstans, hogy tudjunk mutatni a konstans konstruktor paraméterre.
	const State<LABEL_TYPE>* state;

	INPUT_TYPE input; // A bemeneti szekvencia egy eleme.
	
	const State<LABEL_TYPE>* nextState; // A következő állapot, ahova ugorhatunk.
public:
	// TODO: Ide jön egy konstruktor

	
	// Akkor találunk egyezést a szabállyal, ha a megadott jelenlegi állapot
	// megegyezik a tárolt állapottal, valamint a most érkezett bemeneti elem
	// megegyezik a tárolt inputtal.
	bool match(const State <LABEL_TYPE>& currentState, const INPUT_TYPE& currentInput)
	{
		// 1. Visszatérés igenne, ha matchel, ellenkező esetben hamissal.
		
	}

	// Visszaadjuk a következő állapotot. Konstanst ad vissza,
	// hogy semmiképp se tudjuk módosítani a nextState-t.
	const State<LABEL_TYPE>& getNextState() const
	{
		// 1. Visszatérés
		
	}

	// Megjegyzés: most megelégszünk az alapértelmezett operator=-vel
	// (ami egyébként kell a Vector dinamikus adatkezelése miatt).
};