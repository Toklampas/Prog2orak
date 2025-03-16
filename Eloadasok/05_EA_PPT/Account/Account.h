#pragma once
class Account
{
	int balanceEUR;
	static int rate;
	static const int MAXRATE;
	const unsigned accountId;
public:

	Account(unsigned idparam, int openingBalance) :balanceEUR(openingBalance), accountId(idparam){}
	~Account();
	int getBalanceHUF() const;
	int getAccountId() const;

	static void setRate(int prate);

};



