#include <stdio.h>
#include <iostream>

using namespace std;

class Seged {
	double segedAdat;
public:
	Seged() { segedAdat = 1.0; }
};

class Tartalmazott {
	int tartalmazottAdat;
public:
	Tartalmazott() { tartalmazottAdat = 0; }
	Tartalmazott(int param) { tartalmazottAdat = param; }
};


class Szulo {
	Seged seged;
	int szuloAdat;
public:
	Szulo() { szuloAdat = 0; }
	Szulo(int param) { szuloAdat = param; }
};

class Leszarmazott : public Szulo {
	Tartalmazott adat;
public:
	Leszarmazott(int szuloAdatParam, int tartalmazottAdatParam) 
		: Szulo(szuloAdatParam), adat(tartalmazottAdatParam) 
	{}
};


int main(int argc, char* argv[]) {



	getchar();
	return 0;

}