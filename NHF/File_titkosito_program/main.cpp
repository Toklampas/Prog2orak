#include "list.h"
#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    List list;

    list.buildFromFile("feladat.be");

    list.printToFile("feladat.ki");

    list.encodeFile("feladat.be", "kodolt.ki");

	std::cout << "A k�dolt f�jl elk�sz�lt: kodolt.ki\n";
    return 0;
}