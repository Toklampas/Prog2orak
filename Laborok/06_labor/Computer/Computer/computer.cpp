#include "computer.h"
#include <cstdio>

unsigned Computer::nextId = 0; // statikus változónak így adunk értéket

Computer::Computer() : id(nextId++), clockSpeed(3000) {}

Computer::Computer(const Computer& theOther) : id(nextId++)
{
	clockSpeed = theOther.clockSpeed;
}

unsigned Computer::getClockSpeed() const
{
	return clockSpeed;
}

void Computer::print() const
{
	printf("Computer id:%d, clock speed:%d\n", id, clockSpeed);
}

void friendlyPrint(const Computer& c)
{
	printf("Computer id:%d, clock speed:%d\n", c.id, c.clockSpeed);
}