#include "node.h"
#include <iostream>

#include "memtrace.h"

Node::Node(char ch) : letter(ch), down(nullptr), next(nullptr), count(0), code(0) {}

Node::~Node() {
	//std::cout << "Diagnostic: Deleting node with letter: " << letter << std::endl;
}

char Node::getLetter() const { return letter; }
Node* Node::getDown() const { return down; }
Node* Node::getNext() const { return next; }
int Node::getCount() const { return count; }
int Node::getCode() const { return code; }

Node*& Node::getDownRef() { return down; }
Node*& Node::getNextRef() { return next; }

void Node::setDown(Node* ptr) { down = ptr; }
void Node::setNext(Node* ptr) { next = ptr; }
void Node::incrementCount() { ++count; }
void Node::setCode(int c) { code = c; }