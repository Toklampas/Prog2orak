#include <iostream>
#include "printer.h"

using namespace std;

//A serialNo és a price paramétereket is el kell tárolnunk valahol
Printer::Printer(unsigned serialNo, unsigned price, unsigned cartridgePrice): Equipment(serialNo, price), cartridgePrice(cartridgePrice){}

void Printer::setCartridgePrice(unsigned cartridgePrice)
{
	this->cartridgePrice = cartridgePrice;
}

unsigned Printer::getCartridgePrice() const
{
	return cartridgePrice;
}

void Printer::print() const
{
	cout << "Serial Number: " << serialNumber << " Price: " << price << " HUF" <<" Cartridge Price (Printer):" << cartridgePrice;
}
