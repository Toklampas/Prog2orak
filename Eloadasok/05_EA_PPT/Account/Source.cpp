#include <stdio.h>
#include <iostream>
#include "Account.h"

using namespace std;

int main(int argc, char* argv[]) {

	Account a1(123, 100);
	a1.setRate(310);
	printf("a1 balance: %d HUF\n", a1.getBalanceHUF());

	//Ugyanannyi eur van benne
	//Konstatnssa tettuk
	const Account a2(312, 100);
	//Kozben felment az arfolyam
	//a2.setRate(350);

	//a1 nem tud rola, hogy felment az arfoylam, ha a rate objektumpeldanyhoz kotodik
	printf("%d balance: %d HUF :-O\n", a2.getAccountId(), a2.getBalanceHUF());
	printf("%d balance: %d HUF :-O\n", a1.getAccountId(), a1.getBalanceHUF());



	getchar();
	return 0;

}