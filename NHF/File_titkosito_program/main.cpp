#include "list.h"
#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    List list;

    list.buildFromFile("feladat.be");

    list.printToFile("feladat.ki");

    list.encodeFile("feladat.be", "kodolt.ki");

	std::cout << "A kódolt fájl elkészült: kodolt.ki\n";
    return 0;
}