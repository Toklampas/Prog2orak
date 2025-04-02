#include <ctime>
#include <iostream>
#include "company.h"
#include "person.h"

using namespace std;

int main() {
	time(NULL);
	Company ceg1;	// ID: 0
	Company ceg2("Masodik ceg", "1234567890"); // ID: 1
	ceg2.setVATIN("12345678901");
	Company ceg3("Harmadik ceg", "00000000000"); // ID: 2
	Company ceg4(ceg3); // ID: 3
	ceg4.setBusinessName("Negyedik ceg");
	Person m1("Elso", "maganszemely", "0123456789"); // ID: 4
	Person m2(m1); // ID: 5
	m2.setFirstName("Masodik");

	cout << endl << ceg3 << m2 << endl;
	return 0;
}
