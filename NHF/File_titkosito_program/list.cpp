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



// Kódolt szöveg elõállítása
void List::encodeFile(const std::string& inputfile, const std::string& outfile) const {
    std::ifstream in(inputfile);
    std::ofstream out(outfile);

    if (!in) {
        std::cerr << "Nem sikerült megnyitni: " << inputfile << "\n";
        return;
    }
    if (!out) {
        std::cerr << "Nem sikerült megnyitni: " << outfile << "\n";
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