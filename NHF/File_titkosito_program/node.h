#pragma once
#include <stdexcept>

#include "memtrace.h"

class Node {
private:
	char letter; // character stored in the node
	Node* down; // pointer to the next level (down)
	Node* next; // pointer to the next node at the same level
    int count; // the number of occurences of a given word
	int code; // code assigned to the word ending at this node

public:
    Node(char ch);
    ~Node();

    char getLetter() const;
    Node* getDown() const;
    Node* getNext() const;
    int getCount() const;
    int getCode() const;
    Node*& getDownRef();
    Node*& getNextRef();

    void setDown(Node* ptr);
    void setNext(Node* ptr);
    void incrementCount();
    void setCode(int c);
};
