#pragma once
#include "node.h"
#include <string>
#include <stdexcept>

class List {
private:
	Node* root; // Pointer to the root of the list
	int nextCode; // The next code to be assigned to a wordq

    void printWords(Node* node, std::string& path, std::ofstream& out) const;
    void freeNodes(Node* node);

    void visualize(Node* node, const std::string& prefix, bool isLast) const;

public:
    List();
    ~List();

    void insertWord(const std::string& word);
    int getWordCode(const std::string& word) const;
    void encodeFile(const std::string& inputfile, const std::string& outfile) const;


    friend std::ofstream& operator<<(std::ofstream& out, const List& list);
    friend std::ifstream& operator>>(std::ifstream& in, List& list);

    void visualize() const;
};