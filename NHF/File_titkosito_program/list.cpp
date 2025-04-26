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

// Bemeneti f�jl feldolgoz�sa, a szavak kisbet�s�t�se �s besz�r�sa a f�ba
void List::buildFromFile(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Nem siker�lt megnyitni: " << filename << "\n";
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
        
		// Megkeress�k, hogy a jelenlegi karakternek megfelel� node l�tezik-e
        while (*node && (*node)->getLetter() != currentChar)
            node = &((*node)->getNextRef());
		// Ha nem l�tezik, akkor l�trehozzuk
        if (!(*node))
            *node = new Node(currentChar);
        
		// Megn�zz�k, hogy lefele l�tezik-e node, ha nem, l�trehozunk egy placeholder node-ot (a sz� jelenlegi v�g�n)
        if (!(*node)->getDown())
            (*node)->setDown(new Node('\0'));

		// Lejjebb l�p�nk a f�ban, hogy a k�vetkez� karaktert is be tudjuk illeszteni
        node = &((*node)->getDownRef());
        ++currentCharIndex;
    }

	//Ha nem l�tezik lez�r� node, akkor l�trehozzuk (ez jel�li a sz� v�g�t)
    if (!(*node))
        *node = new Node('\0');

	// N�velj�k a sz� el�fordul�sainak sz�m�t
    (*node)->incrementCount();

	// Ha a node-hoz m�g nem lett k�d rendelve, akkor hozz�rendel�nk egyet
    if ((*node)->getCode() == 0)
        (*node)->setCode(nextCode++);
}

void List::printWords(Node* node, std::string& path, std::ofstream& out) const {
	// Alapeset: ha a node nullptr, akkor kil�p�nk
    if (!node)
        return;
	// Ha a node nem nullptr, akkor az aktu�lis karaktert hozz�adjuk a path-hoz
    if (node->getLetter())
        path.push_back(node->getLetter());
	// Ha count nagyobb mint 0, akkor a sz� v�g�hez �rt�nk, ki�rjuk a code-ot, a count-ot �s a sz�t
    if (node->getCount() > 0)
        out << node->getCode() << '\t' << node->getCount() << '\t' << path << '\n';
	// A sz� k�vetkez� karakter�hez l�p�nk
    printWords(node->getDown(), path, out);
    if (node->getLetter())
        path.pop_back();
	// A k�vetkez� sz�ra l�p�nk
    printWords(node->getNext(), path, out);
}

void List::printToFile(const std::string& filename) const {
    std::ofstream out(filename);
	if (!out)
    {
		std::cerr << "Nem siker�lt megnyitni: " << filename << "\n";
		return;
	}
	if (!root)
    {
		std::cerr << "A fa ures.\n";
		return;
	}

    std::string path;

	// Fejl�c ki�r�sa
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

		// Megkeress�k a megfelel� node-ot a jelenlegi karakterhez
        while (currentNode && currentNode->getLetter() != currentChar)
            currentNode = currentNode->getNext();

		// Ha nem tal�lunk megfelel� node-ot, akkor a sz� nem eleme a list�nak
        if (!currentNode)
            return 0;

		// Az input sz� k�vetkez� karakter�hez l�p�nk �s azzal is elv�gezz�k a keres�st
        node = currentNode->getDown();
        ++currentCharIndex;
    }

	// Ha az eg�sz sz� megtal�lhat�, visszaadjuk a k�dj�t
    if (node && currentCharIndex == word.size() && node->getCode() != 0)
        return node->getCode();

    return 0;
}

// K�dolt sz�veg el��ll�t�sa
void List::encodeFile(const std::string& inputFileName, const std::string& outputFileName) const {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile)
    {
        std::cerr << "Nem siker�lt megnyitni: " << inputFileName << "\n";
        return;
    }
    if (!outputFile) 
    {
        std::cerr << "Nem siker�lt megnyitni: " << outputFileName << "\n";
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