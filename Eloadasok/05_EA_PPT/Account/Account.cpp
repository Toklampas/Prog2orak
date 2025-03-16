#include "Account.h"




Account::~Account()
{
}

int Account::getBalanceHUF() const
{
	return balanceEUR * Account::rate;
}

inline int Account::getAccountId() const { 
	//Ez nem lehet, mert konstans a tagfuggveny
    //balanceEUR = 100000000;
	return accountId; 
}

void Account::setRate(int prate)
{
	if(prate >0 && prate <= MAXRATE)
		rate = prate;
}

int Account::rate = 300;
const int Account::MAXRATE = 1000;