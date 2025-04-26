#include "list.h"
#include "node.h"
#include <fstream>
#include <iostream>

List::List() : root(nullptr), nextCode(1) {}

List::~List() {
    freeNodes(root);
}

void List::freeNodes(Node* node) {
    if (node) {
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
                insert(word);
                word.clear();
            }
    }
    if (!word.empty())
        insert(word);
}

void List::insert(const std::string& word) {
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
    if (!node) return;
    if (node->getLetter()) path.push_back(node->getLetter());
    if (node->getCount() > 0) {
        out << node->getCode() << '\t' << node->getCount() << '\t' << path << '\n';
    }
    printWords(node->getDown(), path, out);
    if (node->getLetter()) path.pop_back();
    printWords(node->getNext(), path, out);
}

void List::printToFile(const std::string& filename) const {
    std::ofstream out(filename);
    std::string path;
    out << "id\tno\tword\n";
    printWords(root, path, out);
}

int List::getWordCode(const std::string& word) const {
    Node* node = root;
    size_t idx = 0;

    while (node && idx < word.size()) {
        char ch = word[idx];
        Node* cur = node;

        // Traverse siblings to find the matching character
        while (cur && cur->getLetter() != ch) {
            cur = cur->getNext();
        }

        // If no matching node is found, the word is not in the trie
        if (!cur) {
            return 0; // Return 0 to indicate the word doesn't exist
        }

        // Move down to the next level
        node = cur->getDown();
        ++idx;
    }

    // If we have traversed the entire word, check the final node's code
    if (node && idx == word.size() && node->getCode() != 0) {
        return node->getCode();
    }

    return 0; // Return 0 if the word is not found or has no code
}



// K�dolt sz�veg el��ll�t�sa
void List::encodeFile(const std::string& inputfile, const std::string& outfile) const {
    std::ifstream in(inputfile);
    std::ofstream out(outfile);

    if (!in) {
        std::cerr << "Nem siker�lt megnyitni: " << inputfile << "\n";
        return;
    }
    if (!out) {
        std::cerr << "Nem siker�lt megnyitni: " << outfile << "\n";
        return;
    }

    std::string word;
    char ch;
    while (in.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += std::tolower(static_cast<unsigned char>(ch));
        }
        else {
            if (!word.empty()) {
                int code = getWordCode(word);
                out << code << " ";
                word.clear();
            }
            out << ch;
        }
    }
    if (!word.empty()) {
        int code = getWordCode(word);
        out << code << " ";
    }
}