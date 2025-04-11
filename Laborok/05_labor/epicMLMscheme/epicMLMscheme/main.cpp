#include <ctime>
#include "Person.h"

int main()
{
	srand(time(NULL));
	Person p1("Nagy", "Zoltan");
	//Person p2("Szinten", "Zoltan", "0123456789");

	p1.print();
	return 0;
}