#include <stdio.h>
#include <iostream>

using namespace std;

//A 2. esethez: tfh van egy interfesz osztalyunk, amit pl. a Print fv. var
class IBarcodePrinter {
public:
	virtual void PrintBarcode() = 0;
};

//A 2. esethez a nyomtato fv.
void Print(IBarcodePrinter& printer) {
	printer.PrintBarcode();
}

//A 2. esethez a fenti interfesz alapjan template osztalyt akarok majd letrehozni, ahol meg mindig nem tudom, milyen tipus az id, amit a vonalkodba kene nyomtatni

template <class ID_TYPE, class DATE_TYPE>
class Product {
	ID_TYPE id;
	DATE_TYPE expiration; //legyen def. konstruktora!
public:
	Product(ID_TYPE param) : id(param) {} //ID_TYPE masolo konstruktor!
	ID_TYPE getId() { return id; } //lehet referencia is, ez most nem erdekes
};


//... 1. eset. Az ID int, a datum long tipusu lesz a leszarmazottban
class ABCBAProduct : public Product<int, long> {
	//... 1. eset. Az ID int, a datum long tipusu lesz a leszarmazottban
};

//2. eset, ld. fenn a leirast
//Egy ko0zonseges osztály alapján leszármazott template-et hozunk létre
template <class ID_TYPE>
class SuperPrinter : public IBarcodePrinter {
	ID_TYPE barCodeToPrint;
public:
	SuperPrinter() {
		//...TODO konstruald meg
	}
	void PrintBarcode()
	{
		cout << "Printing lots of " << typeid(ID_TYPE).name() << "s..." << endl;
	}
};


//3. eset: Az õs template-bõl példányosított osztály (tehát nem template!), a leszármazott template osztály
//Olyan Product, ahol tudjuk, hogy a datum long tipusu, de az id tipust nem ismerjuk
template <class ID_TYPE>
class DutyFreeProduct : public Product<ID_TYPE, long> {
public: 
	DutyFreeProduct(ID_TYPE param) : Product(param) {
		//...
	}
};


//4. eset: template parameterben megadott ososztaly
//Pl. tervezésnél még nem ismerjük a bárkódnyomtató komponens driverét. 
//De tudjuk, hogy majd nyomtatni akarjuk, cask még nem ismert az interfész (vagy számítunk rá, hogy lecserélik stb.)
template<class ID_TYPE, class PRINTER_INTERFACE>
class PrintableProduct : public DutyFreeProduct<ID_TYPE>, public PRINTER_INTERFACE {
public:
	PrintableProduct(ID_TYPE param) : DutyFreeProduct(param) {}
};




int main(int argc, char* argv[]) {

	//3. eset hasznalata. Megadjuk, hogy az id az int
	DutyFreeProduct<int> prod(5);

	//4. esethez: no vegre megkaptuk a kulso nyomtato komponenst: a Print fuggvenyt, illetve a SuperPrinter driveret. Ezert igy hasznaljuk:
	PrintableProduct<int, SuperPrinter<int>> prod2('a');
	Print(prod2);

	getchar();
	return 0;

}