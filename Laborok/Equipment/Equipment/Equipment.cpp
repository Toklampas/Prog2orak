#include <iostream>
#include "Equipment.h"

using namespace std;

Equipment::Equipment(unsigned pSerialNumber, unsigned pPrice) : serialNumber(pSerialNumber), price(pPrice)
{
}

void Equipment::setPrice(unsigned pPrice)
{
	price = pPrice;
}

void Equipment::setSerialNumber(unsigned pSerialNumber)
{
	serialNumber = pSerialNumber;
}

unsigned Equipment::getPrice() const
{
	return price;
}

unsigned Equipment::getSerialNumber() const
{
	return serialNumber;
}

void Equipment::print() const
{
	cout << " Serial Number: " << serialNumber << " Price: " << price << " HUF";
}
