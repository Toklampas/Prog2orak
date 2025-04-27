#include "list.h"
#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    List list;

    std::ifstream inputFile("feladat.be");
	if (!inputFile) {
		std::cerr << "Nem sikerult megnyitni a bemeneti fajlt!\n";
		return 1;
	}
	inputFile >> list;
    inputFile.close();
	std::cout << "A szavak beolvasva a listaba.\n";

    std::ofstream outputFile("feladat.ki");
	if (!outputFile) {
		std::cerr << "Nem sikerult megnyitni a kimeneti fajlt!\n";
		return 1;
	}
    outputFile << list;
    outputFile.close();
	std::cout << "A szavak listaja kiirva a fajlba.\n";


    list.encodeFile("feladat.be", "kodolt.ki");
	std::cout << "A kodolt szoveg kiirva a fajlba.\n";

	list.visualize();

    return 0;
}