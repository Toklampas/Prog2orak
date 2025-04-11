#pragma once
#include <iostream>

using namespace std;

class Product {
private:
    static unsigned totalProducts;
    static const double MAX_PRICE;  // maximum �r
    const unsigned id;
    const string name;
    const double price;

public:
    Product(int pid, const std::string& pname, double pprice);

    ~Product();

    static unsigned getTotalProducts(); //Objektumt�l f�ggetlen�l visszaadja a darabsz�mot

    static const double getMaxPrice(); //A max lehets�ges �r, sosem v�ltozik

    const int getId() const;

    const string getName() const;

    const double getPrice() const;

    void printDetails() const;
};
