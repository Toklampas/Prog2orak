#pragma once

class Node {
private:
    char letter;
    Node* down;
    Node* next;
    int count;
    int code;

public:
    Node(char ch);
    ~Node();

    char getLetter() const;
    Node* getDown() const;
    Node* getNext() const;
    int getCount() const;
    int getCode() const;
    Node*& getDownRef();

    void setDown(Node* ptr);
    void setNext(Node* ptr);
    void incrementCount();
    void setCode(int c);
};
