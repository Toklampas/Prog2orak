#include "list.h"
#include "node.h"
#include <fstream>
#include <iostream>

using namespace std;

List::List() : root(nullptr), nextCode(1) {}

List::~List() {
    try
    {
        freeNodes(root);
    }
    catch (...)
    {
        cerr << "Error while freeing nodes in destructor!" << endl;
    }
}

void List::freeNodes(Node* node) {
    if (node)
    {
        freeNodes(node->getDown());
        freeNodes(node->getNext());
        delete node;
    }
}

void List::insertWord(const string& word) {
    try {
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
    catch (const bad_alloc& ex)
    {
        throw runtime_error("Memory allocation failed while inserting word: " + word);
	}
	catch (...)
	{
		throw runtime_error("Unknown error occurred while inserting word: " + word);
	}
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

int List::getWordCode(const string& word) const {
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
void List::encodeFile(const string& inputFileName, const string& outputFileName) const {
    try {
        ifstream inputFile(inputFileName);
        if (!inputFile)
            throw runtime_error("Failed to open input file: " + inputFileName);

        ofstream outputFile(outputFileName);
        if (!outputFile)
            throw runtime_error("Failed to open output file: " + outputFileName);


        string word;
        char ch;

        while (inputFile.get(ch))
        {
            if (std::isalpha(ch))
                word += tolower(ch);
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
	catch (const exception& ex)
	{
        throw runtime_error("Error during file encoding: " + string(ex.what()));
	}
	catch (...)
	{
		throw runtime_error("Unknown error occurred during file encoding.");
	}
}

std::ofstream& operator<<(std::ofstream& out, const List& list) {
    try
    {
        if (!out)
            throw runtime_error("Failed to open output file stream.");
        if (!list.root)
        {
            out << "The list is empty." << endl;
            return out;
        }

        string path;
        out << "id\tno\tword" << endl;
        list.printWords(list.root, path, out);
    }
    catch (const exception& ex)
    {
        cerr << "Error during writing to output file: " << ex.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error occurred during writing to output file." << endl;
    }
    return out;
}

std::ifstream& operator>>(std::ifstream& in, List& list) {
    try
    {
        if (!in)
        {
            throw runtime_error("Failed to open input file stream.");
        }

        string word;
        char ch;

        while (in.get(ch))
        {
            if (std::isalpha(ch))
                word += tolower(ch);
            else
                if (!word.empty())
                {
                    list.insertWord(word);
                    word.clear();
                }
        }
        if (!word.empty())
            list.insertWord(word);
    }
    catch (const exception& ex)
    {
        cerr << "Error during reading from input file: " << ex.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown error occurred during reading from input file." << endl;
    }
    return in;
}


// Recursive helper function for visualization
void List::visualize(Node* node, const string& prefix, bool isLast) const {
    if (!node) return;

    // Print the current node
    cout << prefix;
    cout << (isLast ? "\\-- " : "|-- ");
    cout << "'" << node->getLetter() << "'";

    // If this node has a code or count, print them
    if (node->getCount() > 0) {
        cout << " (count: " << node->getCount() << ", code: " << node->getCode() << ")";
    }
    cout << endl;

    // Build the prefix for child nodes
    string newPrefix = prefix + (isLast ? "    " : "|   ");

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
    if (!root)
    {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "List Visualization:" << endl << endl;
    visualize(root, "", true);    
}