#include <stdio.h>
#include <iostream>
#include "PriceComponent.h"
#include "VatComponent.h"

using namespace std;



class NewCar : public IWare, public IAccountable {
	int price;
	int VAT;
public:
	NewCar(int param) : price(param), VAT(27) {}
	int getPrice() const { return price; }
	int getVAT() const { return VAT; }
};


class Consultation : public IWare, public IAccountable {
	int duration;
	int VATdata; // mert itt igy taroljak es jelolik...
	static const int pricePerMinute = 500;
public:
	Consultation(int param) :duration(param), VATdata(12) {}
	int getPrice() const { return duration*pricePerMinute; }
	int getVAT() const { return VATdata; }
};

int main(int argc, char* argv[]) {

	NewCar car(1000000);
	Consultation cons(1000);

	PrintPrice(car);
	PrintPrice(cons);
	AccountingDoSomethingWithVAT(car);
	AccountingDoSomethingWithVAT(cons);

	getchar();
	return 0;

}