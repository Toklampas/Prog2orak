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
//        if (!(*node)->getDown())
//           (*node)->setDown(new Node('\0'));

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
        else
        {
            if (!word.empty())
            {
                int code = getWordCode(word);
                outputFile << code << " ";
                word.clear();
            }
            outputFile << ch;
        }
    }
    if (!word.empty())
    {
        int code = getWordCode(word);
        outputFile << code << " ";
    }

	inputFile.close();
	outputFile.close();
}

std::ofstream& operator<<(std::ofstream& out, const List& list) {
    if (!out)
    {
        std::cerr << "Failed to open output file stream.\n";
        return out;
    }
    if (!list.root)
    {
        out << "The list is empty.\n";
        return out;
    }

    std::string path;

    out << "id\tno\tword\n";
    list.printWords(list.root, path, out);
    return out;
}

std::ifstream& operator>>(std::ifstream& in, List& list) {
    if (!in)
    {
        std::cerr << "Failed to open input file stream.\n";
        return in;
    }

    std::string word;
    char ch;

    while (in.get(ch))
    {
        if (std::isalpha(ch))
            word += std::tolower(ch);
        else
            if (!word.empty())
            {
                list.insertWord(word);
                word.clear();
            }
    }
    if (!word.empty())
        list.insertWord(word);

    return in;
}


// Recursive helper function for visualization
void List::visualize(Node* node, const std::string& prefix, bool isLast) const {
    if (!node) return;

    // Print the current node
    std::cout << prefix;
    std::cout << (isLast ? "\\-- " : "|-- ");
    std::cout << "'" << node->getLetter() << "'";

    // If this node has a code or count, print them
    if (node->getCount() > 0) {
        std::cout << " (count: " << node->getCount() << ", code: " << node->getCode() << ")";
    }
    std::cout << '\n';

    // Build the prefix for child nodes
    std::string newPrefix = prefix + (isLast ? "    " : "|   ");

    // Get the child and sibling nodes
    Node* child = node->getDown();
    Node* sibling = node->getNext();

    // Recursively print child nodes
    if (child) {
        visualize(child, newPrefix, sibling == nullptr); // Pass true if no siblings exist
    }

    // Recursively print sibling nodes
    if (sibling) {
        visualize(sibling, prefix, false); // Sibling is never treated as the last node
    }
}

// Public method for visualizing the list
void List::visualize() const {
    if (!root) {
        std::cout << "The list is empty.\n";
        return;
    }

    std::cout << "List Visualization:\n";
    visualize(root, "", true);
}