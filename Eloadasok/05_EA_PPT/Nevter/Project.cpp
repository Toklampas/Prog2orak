#include <string>
#include <algorithm>
#include "Source.h"

using namespace std;
int intarray[] = { 32,71,12,45,26,80,53,33 };

int main(int argc, char* argv[]) {

	std::string str1;
	mylib::sort(intarray, intarray + 7);

	//Ha nem akarom scope ele kiirni a nevteret, akkor az adott deklaracios regiora hasznlahato az using

	using namespace std;
	//ez igy pl. std-s lesz.
	string s2;

	getchar();
	return 0;

}

