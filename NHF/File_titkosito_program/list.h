#pragma once
#include "node.h"
#include <string>

class List {
private:
    Node* root;
    int nextCode;

    void printWords(Node* node, std::string& path, std::ofstream& out) const;
    void freeNodes(Node* node);

public:
    List();
    ~List();

    void insert(const std::string& word);
    void printToFile(const std::string& filename) const;
    int getWordCode(const std::string& word) const;

    void buildFromFile(const std::string& filename);
    void encodeFile(const std::string& inputfile, const std::string& outfile) const;
};