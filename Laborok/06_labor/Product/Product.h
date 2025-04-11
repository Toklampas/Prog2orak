#pragma once
#include <iostream>

using namespace std;

class Product {
private:
    static unsigned totalProducts;
    static const double MAX_PRICE;  // maximum ár
    const unsigned id;
    const string name;
    const double price;

public:
    Product(int pid, const std::string& pname, double pprice);

    ~Product();

    static unsigned getTotalProducts(); //Objektumtól függetlenül visszaadja a darabszámot

    static const double getMaxPrice(); //A max lehetséges ár, sosem változik

    const int getId() const;

    const string getName() const;

    const double getPrice() const;

    void printDetails() const;
};
