#include <stdio.h>
#include <iostream>
#include "person.h"
#include "printer.h"

using namespace std;


int main(int argc, char* argv[]) {

	person tanarseged;
	strcpy_s(tanarseged.name, 6, "Sanyi");
	tanarseged.salary = 400000;
	printf("Teszteles: %s fizetese printer driver hivas elott: %d\n", tanarseged.name, tanarseged.salary);
	printCV(tanarseged);

	printf("Teszteles: %s fizetese printer driver hivas utan: %d\n", tanarseged.name, tanarseged.salary);

	getchar();
	return 0;

}