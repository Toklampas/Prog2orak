#pragma once
#include <string>

class VendingMachine
{
	int drinkNumber; // az italok sz�ma
	std::string* drinks;
public:

	VendingMachine();	
	VendingMachine(const VendingMachine&);
		
	int getDrinkNumber();

	std::string removeOne();
	bool buy(int = 1);
	bool refill(std::string, int);

	void print();
	
	~VendingMachine();
};

