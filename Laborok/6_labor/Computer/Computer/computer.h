#pragma once
#include <stdio.h>

class Computer
{
	static unsigned nextId; // id generálásához
	unsigned id; // 0-1-2-3
	unsigned clockSpeed;
public:
	Computer();
	Computer(const Computer&); //Vigyazz! A masolatnak is egyedi azonositoja legyen!
	unsigned getClockSpeed() const;
	void print() const;
	friend void friendlyPrint(const Computer&); //Ez ne legyen tagfuggveny!
};

void friendlyPrint(const Computer&);