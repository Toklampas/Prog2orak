#include "Product.h"

const double Product::MAX_PRICE = 5000.0;
unsigned Product::totalProducts = 0;

    Product::Product(int pid, const std::string& pname, double pprice)
        : price((pprice > MAX_PRICE) ? MAX_PRICE : pprice), id(pid), name(pname)
    {
        totalProducts++;
    }

    Product::~Product()
    {
        totalProducts--;
    }

    unsigned Product::getTotalProducts()
    {
        return totalProducts;
    }

    const double Product::getMaxPrice()
    {
        return MAX_PRICE;
    }

    const int Product::getId() const
    {
        return id;
    }

    const string Product::getName() const
    {
        return name;
    }

    const double Product::getPrice() const
    {
        return price;
    }

    void Product::printDetails() const
    {
        std::cout << "id: " << Product::getId() << " | ";
        std::cout << "name: " << Product::getName() << " | ";
        std::cout << "price: " << Product::getPrice() << std::endl;
    }