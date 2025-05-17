#include "list.h"
#include "node.h"
#include <fstream>
#include <iostream>

using namespace std;

List::List() : root(nullptr), nextCode(1) {}

List::~List() {
    try
    {
		//cout << "Diagnostic: Freeing nodes in list destructor..." << endl;
        freeNodes(root);
    }
    catch (...)
    {
        cerr << "Error while freeing nodes in destructor!" << endl;
    }
}

// Frees the nodes in the list recursively
void List::freeNodes(Node* node) {
    if (node)
    {
        freeNodes(node->getDown());
        freeNodes(node->getNext());
        delete node;
    }
}

// Inserts a new word into the list
void List::insertWord(const string& word) {
    try {
        Node** node = &root;
        unsigned currentCharIndex = 0;

        while (currentCharIndex < word.size())
        {
            char currentChar = word[currentCharIndex];

			// We search for the node that matches the current character
            while (*node && (*node)->getLetter() != currentChar)
                node = &((*node)->getNextRef());

			// If it doesn't exist, we create it
            if (!(*node))
            {
                *node = new Node(currentChar);
			    //cout << "Diagnostic: Created node for character: " << currentChar << endl;
			}
            

			// We move down the tree to insert the next character
            node = &((*node)->getDownRef());
            ++currentCharIndex;
        }

		// If the ending node doesn't exist, we create it (this marks the end of the word)
        if (!(*node))
        {
            *node = new Node('\0');
			//cout << "Diagnostic: Created end node for word: " << word << endl;
		}

		// We increment the count of occurrences of the word
        (*node)->incrementCount();

		// If the node doesn't have a code yet, we assign one to it
        if ((*node)->getCode() == 0)
            (*node)->setCode(nextCode++);
    }
	// new automatically throws std::bad_alloc if memory allocation fails
    catch (const bad_alloc&)
    {
        throw runtime_error("Memory allocation failed while inserting word: " + word);
	}
	catch (...)
	{
		throw runtime_error("Unknown error occurred while inserting word: " + word);
	}
}

// Prints the words in the list to the output file
void List::printWords(Node* node, std::string& path, std::ofstream& out) const {
	// Base case: if the node is nullptr, we exit
    if (!node)
        return;
	// If the node is not nullptr, we add the current character to the path
    if (node->getLetter())
        path.push_back(node->getLetter());
	// If the count is greater than 0, we have reached the end of a word, we print the code, count and the word itself
    if (node->getCount() > 0)
        out << node->getCode() << '\t' << node->getCount() << '\t' << path << '\n';
	// We go down the tree to find the next character
    printWords(node->getDown(), path, out);
    if (node->getLetter())
        path.pop_back();
	// We go to the next node at the same level (this is the next word)
    printWords(node->getNext(), path, out);
}

int List::getWordCode(const string& word) const {
    Node* node = root;
    unsigned currentCharIndex = 0;

    while (node && currentCharIndex < word.size())
    {
        char currentChar = word[currentCharIndex];
        Node* currentNode = node;

		// We search for the node that matches the current character
        while (currentNode && currentNode->getLetter() != currentChar)
            currentNode = currentNode->getNext();

		// If we don't find a matching node, the word is not in the list
        if (!currentNode)
            return 0;

		// We get the next character of the input word and search for it
        node = currentNode->getDown();
        ++currentCharIndex;
    }

	// If we have reached the end of the word and the node has a code, we return it
    if (node && currentCharIndex == word.size() && node->getCode() != 0)
        return node->getCode();

    return 0;
}

// Encodes the input file and writes the encoded text to the output file
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

		// Read the input file character by character
        while (inputFile.get(ch))
        {
			// If the character is an alphabetic character, we add it to the word and convert it to lowercase
            if (std::isalpha(ch))
                word += tolower(ch);
            else
            {
				// If the character is not an alphabetic character, we write the word code to the output file
                if (!word.empty())
                {
                    int code = getWordCode(word);
                    outputFile << code << " ";
                    word.clear();
                }
				// We write the non-alphabetic character to the output file as is
                outputFile << ch;
            }
        }
		// If we reach the end of the file and there is still a word left, we write the last word code to the output file
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

// Overloaded operator to write the list to an output file
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

// Overloaded operator to read words from an input file and insert them into the list
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


// Private visualization function to print the list structure
void List::visualize(Node* node, const string& prefix, bool isLast) const {
	// Base case: if the node is nullptr, we exit
    if (!node) return;

	// Print the prefix for the current node
    cout << prefix << (isLast ? "\\-- " : "|-- ");

    // Print the node's letter or "(end)" if it's the end-of-word node
    if (node->getLetter() == '\0')
        cout << "(end)";
    else
        cout << "'" << node->getLetter() << "'";

	// If the node has a code, we print its count and code
    if (node->getCount() > 0)
        cout << " (count: " << node->getCount() << ", code: " << node->getCode() << ")";
    cout << endl;

    // Build the prefix for the next level
    string downPrefix = prefix + (isLast ? "    " : "|   ");

    // Count number of next nodes 
	// We need this to determine for each node if it's the last one or not
    Node* down = node->getDown();
    int nNext = 0;
    for (Node* c = down; c; c = c->getNext())
        ++nNext;

	// We call the visualization function recursively for each node
    int i = 0;
    for (Node* c = down; c; c = c->getNext(), ++i)
    {
        bool last = (i == nNext - 1);
        visualize(c, downPrefix, last);
    }
}

// Public function to visualize the list
void List::visualize() const {
    if (!root)
		throw runtime_error("The list couldn't be visualized, because it's empty");

    cout << "List Visualization:" << endl << endl;

	// Count the number of next nodes at the root level
    int nNext = 0;
    for (Node* c = root; c; c = c->getNext())
        ++nNext;

    int i = 0;
    for (Node* c = root; c; c = c->getNext(), ++i)
    {
		// For each root level node, we call the private visualization function, we also check if it's the last node
        bool last = (i == nNext - 1);
        visualize(c, "", last);
    }
}