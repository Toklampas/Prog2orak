#include "Point.h"
#include <stdio.h>

//Tfh ez a kenyszerunk x es y koordinatakra
//Lesz ennel jobb otletunk is kesobb (konstans tagvaltozo)
const int MAX_COORD = 1024;

//Default konstruktort atirtuk, hogy inicializalja a tagvaltozokat.
Point::Point()
{
	x = 0;
	y = 0;
}

//Jo otletnek tunt egy ketparamteres konstruktor, ami rogton beallitja a tagvaltozokat
Point::Point(int xparam, int yparam)
{
	x = 0;
	setX(xparam);
	y = 0;
	setY(yparam);
}

//Masolokonstruktor. Itt most az automatikus masolokonstruktor is ugyanezt csinalna (sekely masolat), na de majd jovo oran a Person...
Point::Point(const Point & theOther)
{
	//a this nem is kene
	//Nem is ellenorizzuk, hisz feltetelezhetjuk, hogy a masik objektum is valid
	//A privat tagvaltozohoz is hozzaferunk, mert ugyanaz az osztaly
	this->x = theOther.x;
	this->y = theOther.y;

}


void Point::draw()
{
	printf("Point here: %d, %d\n", x, y);

}

void Point::setX(int xparam)
{
	//A Point tud magara vigyazni
	if (xparam >= 0 && xparam <= MAX_COORD)
		x = xparam;
}

void Point::setY(int yparam)
{
	//A Point tud magara vigyazni
	if (yparam >= 0 && yparam <= MAX_COORD)
		y = yparam;

}


Point::~Point()
{
}
