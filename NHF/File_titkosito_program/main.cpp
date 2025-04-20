#include "list.h"
#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    Trie trie;

    trie.buildFromFile("feladat.be");

    trie.printToFile("feladat.ki");

    trie.encodeFile("feladat.be", "kodolt.ki");

	std::cout << "A k�dolt f�jl elk�sz�lt: kodolt.ki\n";
    return 0;
}