#include "list.h"
#include "node.h"
#include <fstream>
#include <iostream>

List::List() : root(nullptr), nextCode(1) {}

List::~List() {
    freeNodes(root);
}

void List::freeNodes(Node* node) {
    if (node)
    {
        freeNodes(node->getDown());
        freeNodes(node->getNext());
        delete node;
    }
}

// Bemeneti fájl feldolgozása, a szavak kisbetûsítése és beszúrása a fába
void List::buildFromFile(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Nem sikerült megnyitni: " << filename << "\n";
        return;
    }

    std::string word;
    char ch;

    while (inputFile.get(ch))
    {
        if (std::isalpha(ch))
            word += std::tolower(ch);
        else
            if (!word.empty())
            {
                insertWord(word);
                word.clear();
            }
    }
    if (!word.empty())
        insertWord(word);
}

void List::insertWord(const std::string& word) {
    Node** node = &root;
    unsigned currentCharIndex = 0;

    while (currentCharIndex < word.size())
    {
        char currentChar = word[currentCharIndex];
        
		// Megkeressük, hogy a jelenlegi karakternek megfelelõ node létezik-e
        while (*node && (*node)->getLetter() != currentChar)
            node = &((*node)->getNextRef());
		// Ha nem létezik, akkor létrehozzuk
        if (!(*node))
            *node = new Node(currentChar);
        
		// Megnézzük, hogy lefele létezik-e node, ha nem, létrehozunk egy placeholder node-ot (a szó jelenlegi végén)
        if (!(*node)->getDown())
            (*node)->setDown(new Node('\0'));

		// Lejjebb lépünk a fában, hogy a következõ karaktert is be tudjuk illeszteni
        node = &((*node)->getDownRef());
        ++currentCharIndex;
    }

	//Ha nem létezik lezáró node, akkor létrehozzuk (ez jelöli a szó végét)
    if (!(*node))
        *node = new Node('\0');

	// Növeljük a szó elõfordulásainak számát
    (*node)->incrementCount();

	// Ha a node-hoz még nem lett kód rendelve, akkor hozzárendelünk egyet
    if ((*node)->getCode() == 0)
        (*node)->setCode(nextCode++);
}

void List::printWords(Node* node, std::string& path, std::ofstream& out) const {
	// Alapeset: ha a node nullptr, akkor kilépünk
    if (!node)
        return;
	// Ha a node nem nullptr, akkor az aktuális karaktert hozzáadjuk a path-hoz
    if (node->getLetter())
        path.push_back(node->getLetter());
	// Ha count nagyobb mint 0, akkor a szó végéhez értünk, kiírjuk a code-ot, a count-ot és a szót
    if (node->getCount() > 0)
        out << node->getCode() << '\t' << node->getCount() << '\t' << path << '\n';
	// A szó következõ karakteréhez lépünk
    printWords(node->getDown(), path, out);
    if (node->getLetter())
        path.pop_back();
	// A következõ szóra lépünk
    printWords(node->getNext(), path, out);
}

void List::printToFile(const std::string& filename) const {
    std::ofstream out(filename);
	if (!out)
    {
		std::cerr << "Nem sikerült megnyitni: " << filename << "\n";
		return;
	}
	if (!root)
    {
		std::cerr << "A fa ures.\n";
		return;
	}

    std::string path;

	// Fejléc kiírása
    out << "id\tno\tword\n";
    printWords(root, path, out);
}

int List::getWordCode(const std::string& word) const {
    Node* node = root;
    unsigned currentCharIndex = 0;

    while (node && currentCharIndex < word.size())
    {
        char currentChar = word[currentCharIndex];
        Node* currentNode = node;

		// Megkeressük a megfelelõ node-ot a jelenlegi karakterhez
        while (currentNode && currentNode->getLetter() != currentChar)
            currentNode = currentNode->getNext();

		// Ha nem találunk megfelelõ node-ot, akkor a szó nem eleme a listának
        if (!currentNode)
            return 0;

		// Az input szó következõ karakteréhez lépünk és azzal is elvégezzük a keresést
        node = currentNode->getDown();
        ++currentCharIndex;
    }

	// Ha az egész szó megtalálható, visszaadjuk a kódját
    if (node && currentCharIndex == word.size() && node->getCode() != 0)
        return node->getCode();

    return 0;
}

// Kódolt szöveg elõállítása
void List::encodeFile(const std::string& inputFileName, const std::string& outputFileName) const {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile)
    {
        std::cerr << "Nem sikerült megnyitni: " << inputFileName << "\n";
        return;
    }
    if (!outputFile) 
    {
        std::cerr << "Nem sikerült megnyitni: " << outputFileName << "\n";
        return;
    }

    std::string word;
    char ch;

    while (inputFile.get(ch))
    {
        if (std::isalpha(ch))
            word += std::tolower(ch);
        else {
            if (!word.empty()) {
                int code = getWordCode(word);
                outputFile << code << " ";
                word.clear();
            }
            outputFile << ch;
        }
    }
    if (!word.empty()) {
        int code = getWordCode(word);
        outputFile << code << " ";
    }

	inputFile.close();
	outputFile.close();
}