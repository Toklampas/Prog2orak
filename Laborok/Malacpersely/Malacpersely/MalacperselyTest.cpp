#include <cstdio>
#include <iostream>
#include "Malacpersely.h"

using namespace std;

int main(int argc, char* argv[]) {

	//Regi tudasunkkal igy oldottuk meg:
	Malacpersely probapersely1;
	probapersely1.bedob(100);
	std::cout << "A probapersely1 erteke " << probapersely1.ertek() << " Ft." << std::endl;

	Malacpersely probapersely2;
	probapersely2.bedob(200);
	std::cout << "A probapersely2 erteke " << probapersely2.ertek() << " Ft." << std::endl;

	probapersely1.atont(probapersely2);
	std::cout << "A probapersely1 erteke atontes utan " << probapersely1.ertek() << " Ft." << std::endl;

	/////////////////////////////////////////////////////////////////
	//A kovetkezokeppen szeretnenk (kommentezd ki sorba a teszteleshez, ahogy az egyes operatorokat megvalositod)
	Malacpersely persely1;
	persely1 = persely1 + 100;
	
	//Ezt akarjuk latni: "A persely1 erteke 100 Ft." - A Ft. -ot nem mi irtuk moge!
	cout << "A persely1 erteke " << persely1 << endl;

	Malacpersely persely2;
	//Vigyazz, ez masik operator.
	//persely2 += 200;
	//cout << "A persely2 erteke " << persely2 << endl;
	//cout << "A persely2 erteke " << (persely2+=500) << endl;

	//persely1 += persely2;
	//cout << "A persely1 erteke atontes utan " << persely1 << endl;
	//cout << "A persely2 pedig ures (0-t varunk): " << persely2 << endl;

	//Ezek mukodni fognak, ha az elozoek is:
	//persely2 += 100;
	//Malacpersely persely3(500);
	
	//Ehhez a kiirashoz at kell gondolnod az operatorok visszateresi erteket, illetve tovabbi operatorra lehet szukseg:
	//cout << "Egy szazas plusz a harom persely osszerteke " << persely1 + persely2 + persely3 + 100 << endl;



	getchar();
	return 0;

}