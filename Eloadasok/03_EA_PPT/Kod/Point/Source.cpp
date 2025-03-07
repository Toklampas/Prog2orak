#include <stdio.h>
#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

int main(int argc, char* argv[]) {

	//Elso otletunk a letrehozasra ez volt. Nem volt jo, mert random ertekek lesznek benne. Erre talaltuk ki a konstruktort.
	//A default konstruktort megirtuk, ami inicializalta az ertekeket. Az init fuggvenyt elvetettuk, mert azt is elfelejtette meghivni a programozo.
	Point p1;
	//Nem engedi, mert privat
	//p1.x = 500;
	//Semmi nem tortenik, mert vigyaz magara a pont...
	p1.setX(2000);
	//Ez OK
	p1.setX(500);
	p1.setX(500);

	//Megegy peldany az ontoformaval
	Point p2;

	//Jo otletnek tunt egy ketparamteres konstruktor, ami rogton beallitja a tagvaltozokat
	Point p3(640, 480);

	//Ez nem ertekadas, hanem a masolokonstruktor hivasa
	Point p4 = p3;

	p1.draw();

	getchar();
	return 0;

}