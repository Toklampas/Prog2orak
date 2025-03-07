#include "Circle.h"
#include <stdio.h>

//Tfh ez a kenyszerunk x es y koordinatakra a kornel is
//Lesz ennel jobb otletunk is kesobb (konstans tagvaltozo)
const int MAX_COORD = 1024;

Circle::Circle()
{
	x = 0;
	y = 0;
	radius = 0;
}


Circle::~Circle()
{
}

void Circle::setX(int xparam)
{
	//A Circle tud magara vigyazni
	if (xparam >= 0 && xparam <= MAX_COORD)
		x = xparam;
}

void Circle::setY(int yparam)
{
	//A Circle tud magara vigyazni
	if (yparam >= 0 && yparam <= MAX_COORD)
		y = yparam;
}

void Circle::setRadius(int radiusParam)
{
	//A Circle tud magara vigyazni
	//TFH radiusra is ez vonatkozik
	if (radiusParam >= 0 && radiusParam <= MAX_COORD)
		radius = radiusParam;

}

void Circle::draw()
{
	printf("Circle here: %d, %d\n", x, y);

}

