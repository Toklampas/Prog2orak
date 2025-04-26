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

void List::insertWord(Node*& node, const std::string& word, size_t idx, int& codeAssigned) {
    if (idx == word.length()) {
        if (!node) node = new Node('\0');
        node->incrementCount();
        if (node->getCode() == 0) node->setCode(nextCode++);
        codeAssigned = node->getCode();
        return;
    }
    char ch = word[idx];
    if (!node) node = new Node(ch);
    Node* cur = node;
    Node* prev = nullptr;
    while (cur && cur->getLetter() != ch) {
        prev = cur;
        cur = cur->getNext();
    }
    if (!cur) {
        cur = new Node(ch);
        prev->setNext(cur);
    }

    if (!cur->getDown()) {
        cur->setDown(new Node('\0'));
    }
    insertWord(cur->getDownRef(), word, idx + 1, codeAssigned);
}

int List::insert(const std::string& word) {
    int code = 0;
    insertWord(root, word, 0, code);
    return code;
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

void List::findWordCode(Node* node, const std::string& word, size_t idx, int& code) const {
    if (!node) return;
    char ch = (idx < word.length()) ? word[idx] : '\0';
    Node* cur = node;
    while (cur && cur->getLetter() != ch) {
        cur = cur->getNext();
    }
    if (!cur) return;
    if (idx == word.length()) {
        code = cur->getCode();
        return;
    }
    findWordCode(cur->getDown(), word, idx + 1, code);
}

int List::getWordCode(const std::string& word) const {
    int code = 0;
    findWordCode(root, word, 0, code);
    return code;
}

// Szövegfájl beolvasása és trie feltöltése
void List::buildFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Nem sikerült megnyitni: " << filename << "\n";
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
                insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        insert(word);
    }
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