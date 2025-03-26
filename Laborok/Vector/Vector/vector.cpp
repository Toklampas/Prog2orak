#include "vector.h"
// #define NDEBUG
#include <cassert>

Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}

Vector::Vector(const Vector& theOther)
{
    //Ezt egy masik fuggveny meghivasaval egyszeruen, 2 sorbol oldd meg!
}

Vector::~Vector()
{
    delete[] pData;
}

unsigned Vector::size() const
{
    return elementNum;
}

unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}

void Vector::clear()
{
    delete[] pData;
    pData = NULL;
    elementNum = 0;
}

bool Vector::erase(unsigned position)
{
    if (position >= elementNum) {
        cerr << "Hibas index";
        return false;
    }

    if (elementNum == 1)
    {
        delete[] pData;
        pData = NULL;
        elementNum = 0;
        return true;
    }

    int* pTemp = new int[--elementNum];
    for (unsigned i = 0, j = 0; i < elementNum + 1; i++, j++)
    {
        if (i == position)
            j--;
        else
            pTemp[j] = pData[i];
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

bool Vector::insert(unsigned position, int element)
{
    if (elementNum == maxElementsNum) {
        std::cerr << "Tobb elem nem fer el a tombben!" << std::endl;
        return false;
    }

    int* pTemp = nullptr;
    if (position < elementNum)
    {
        pTemp = new int[elementNum + 1];

        for (unsigned i = 0, j = 0; i < elementNum; i++, j++)
        {
            if (j == position)
            {
                pTemp[position] = element;
                i--;
            }
            else
                pTemp[j] = pData[i];
        }
        elementNum++;
    }
    else
    {
        pTemp = new int[position + 1];
        for (unsigned i = 0; i < position; i++)
        {
            if (i < elementNum)
                pTemp[i] = pData[i];
            else
                pTemp[i] = 0;
        }
        pTemp[position] = element;
        elementNum = position + 1;
    }
    delete[]pData;
    pData = pTemp;
    return true;
}

Vector& Vector::operator=(const Vector& theOther)
{
    if (this == &theOther) // HIBAKEZELES! (v=v): a mostani elem - osztalypeldany megegyezik-e amibol masolok
        return *this;
    delete[] pData;
    maxElementsNum = theOther.maxElementsNum;

    if (!theOther.elementNum)
    {
        elementNum = 0;
        pData = nullptr;
    }
    else
    {
        elementNum = theOther.elementNum;
        pData = new int[theOther.elementNum]; // a tipusnak kell hogy legyen default kontruktora ilyen esetben (int-nek van)
        for (int i = 0; i < elementNum; i++)
            pData[i] = theOther.pData[i];
    }
    return *this;
}

int& Vector::operator[](unsigned position)
{
    return pData[position];
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    for (int i = 0; i < v.elementNum; i++)
        os << v.pData[1];
    return os;
}

std::istream& operator>>(std::istream&, Vector&)
{
    // TODO: insert return statement here
}
