#include "VatComponent.h"

using namespace std;

void AccountingDoSomethingWithVAT(const IAccountable& acc) {
	cout << "VAT: " << acc.getVAT() << endl;
}