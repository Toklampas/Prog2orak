#include "list.h"
#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    Trie trie;

    trie.buildFromFile("feladat.be");

    trie.printToFile("feladat.ki");

    trie.encodeFile("feladat.be", "kodolt.ki");

	std::cout << "A kódolt fájl elkészült: kodolt.ki\n";
    return 0;
}