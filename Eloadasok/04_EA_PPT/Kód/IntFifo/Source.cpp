#include <stdio.h>
#include <iostream>
#include "IntFifo.h"

using namespace std;

int main(int argc, char* argv[]) {

	IntFifo f1;
	f1.put(1);
	f1.put(2);
	f1.put(3);

	IntFifo f2 = f1;

	int element;
	while(f1.get(element))
		printf("Ez itt: %d\n",element);

	while (f2.get(element))
		printf("Az ott: %d\n", element);


	getchar();
	return 0;

}