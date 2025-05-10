#include <stdio.h>
#include <iostream>

using namespace std;

//Mondjuk o a LemezreIr
void f3() {
	bool hiba = false;
	if (hiba) //tfh hiba
		throw 12; //hibakodot dobunk
	cout << "Nincs hiba, boldogan irunk a lemezre" << endl;
}

//Nem csak int-et dobhatunk
void f2() {
	bool hiba = false; //majd atirjuk true-ra
	if (hiba)
		throw "Szornyuseg tortent. Ez a hiba szovege.";
	//Egymasba agyazott try blokkok. Pl. az f3 hibajat itt feljebb is le tudjuk kezelni.
	try {
		f3();
	}
	catch (int err) {
		cout << "Lekezeljuk a hibat: " << err << endl;
		//throw; //A parameterek nelkuli throw tovabbdobja (ujradobja) a hibat, amit ez az ag elkapott.
	}
	cout << "Ha f3-ban hiba volt, azt lekezeltuk a fenti blokkban, es innen mar folytatodik a vegrehajtas." << endl;
	cout << "Kiveve, ha a ** sor nincs kikommentezve: ott ujradobjuk a hibat." << endl;
}

void f1() {
	//sokmnindent csinal, vegul pedig:
	f2();
	//de nincs benne hibakezeles, mert oneki fogalma sincs, hogy kell megoldani a problemakat
}

//a doIt viszont tudja kezelni a hibakat, csak a hivasi stack aljan lesz elegge
void doIt() {
	try {
		f1();
		cout << "Az f1 lefutott hiba nelkul, ide is eljutottunk" << endl;
	}
	catch (char* err) {
		cout << "Ez a hiba jott: " << err;
		//es itt persze kezljuk is a hibat valahogy
		//Ha egy catch blokkba beleptunk, a tobbi kompatibilitasat mar nem vizsgaljuk, azok nem lesznek vegrehajtva.
	}
	catch (int err) {
		cout << "Hibakod: " << err << endl; 
		//es itt mashogy kezeljuk a hibat.
	}
}


int main(int argc, char* argv[]) {

	doIt();

	getchar();
	return 0;

}