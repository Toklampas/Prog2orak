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

            // Megkeress�k, hogy a jelenlegi karakternek megfelel� node l�tezik-e
            while (*node && (*node)->getLetter() != currentChar)
                node = &((*node)->getNextRef());
            // Ha nem l�tezik, akkor l�trehozzuk
            if (!(*node))
                *node = new Node(currentChar);

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

int List::getWordCode(const string& word) const {
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