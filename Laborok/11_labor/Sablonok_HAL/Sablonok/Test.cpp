#include <iostream>

template <class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T* find_max_elem(T* tomb, int db)
{
    if (db == 0)
        return nullptr;
    T* max_elem = tomb;
    for (int i = 1; i < db; i++)
        if (max_elem < (tomb+i))
            max_elem = (tomb+i);
    return max_elem;
}


// 1.c Egészítsd ki a Vector2D osztályt a find_max_elem feladathoz
class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    double length() const {
	//Fixme!
        return 0;
    }

    bool operator<(Vector2D b)
    {
        return this->length() < b.length();
    }
};

//1.a feladat tesztelése
void swapTest() {
    int x = 5, y = 10;
    std::cout << "Eredeti értékek: x = " << x << ", y = " << y << std::endl;
    //1. valósítsd meg a swap függvénysablont.
    swap(x, y);
    std::cout << "Csere után: x = " << x << ", y = " << y << std::endl;

    double c = 3.14, d = 2.71;
    //2. hívd meg a swap függvényt double típusú változókra is.

}


// 1.b feladat tesztelése - kommentezd ki és hívd meg, ha megvalósítottad a find_max_elem sablont. A lenti kódot ne írd át!

void maxTest() {
    int intArray[] = { 1, 3, 5, 2, 4 };
    double doubleArray[] = { 1.5, 3.2, 2.7, 4.1 };
    int* emptyArray= nullptr;

    int* maxInt = find_max_elem(intArray, 5);
    double* maxDouble = find_max_elem(doubleArray, 4);

    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    if (maxDouble)
        std::cout << "Maximum double: " << *maxDouble << std::endl;
    else
        std::cout << "Empty double array." << std::endl;

    maxInt = find_max_elem(emptyArray, 0);
    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    ////////////////////////////////////
    //1.c feladat - kommentezd ki, ha a Vector2D osztályt megvalósítottad.

    //Vector2D vectors[] = { Vector2D(1.0, 2.0), Vector2D(3.0, 4.0), Vector2D(0.5, 0.5) };
    //Vector2D* maxVector = find_max_elem(vectors, 3);

    //if (maxVector)
    //    std::cout << "Maximum vector length: " << maxVector->length() << std::endl;
    //else
    //    std::cout << "Empty vector array." << std::endl;


}




int main() {

    swapTest();
    maxTest();

    return 0;
}


