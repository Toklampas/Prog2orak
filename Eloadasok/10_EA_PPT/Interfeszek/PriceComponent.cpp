#include "PriceComponent.h"

using namespace std;

void PrintPrice(const IWare& ware)
{
	cout << "Price: " << ware.getPrice() << endl;
}