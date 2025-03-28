#include "vector.h"
// #define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

Vector& Vector::operator=(const Vector& theOther)
{
    if (this == &theOther) //megegyezik e az osztalypeldam azzal amibol masolok, ha egyenlok segmentation fault lenne ha nem foglalkoznank vele
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
        pData = new int[theOther.elementNum]; //kell default konstruktor
        for (unsigned i = 0; i < theOther.elementNum; i++)
        {
            pData[i] = theOther.pData[i];
        }

    }
    return *this; //benne van az osztalypeldany
}

Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}

Vector::Vector(const Vector& theOther)
{
    Vector uj;
    uj = theOther;
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



std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    for (int i = 0; i < v.elementNum; i++)
        os << v.pData[i] << " ";
    return os;
}

int& Vector::at(unsigned position)
{
    if (position >= 0 && position <= elementNum)
        return pData[position];
}

const int& Vector::at(unsigned position) const
{
    if (position >= 0 && position <= elementNum)
    {
        const int eredmeny = pData[position];
        return pData[position];
    }
}

int& Vector::operator[](unsigned position)
{
    return at(position);
}

const int& Vector::operator[](unsigned position) const
{
    const int eredmeny = at(position);
    return eredmeny;
}

void Vector::operator*=(unsigned right)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i]*= right;
    }

}

void Vector::operator+=(unsigned right)
{
    for (unsigned i = 0; i < elementNum; i++)
    {
        pData[i] += right;
    }
}

istream& operator>>(istream& is, Vector& v)
{
    for (unsigned i = 0; i < v.elementNum; i++)
    {
        is >> v.pData[i];
    }
    return is;
}

bool Sorters::ascend(const int& a, const int& b)
{
    return b > a;
}

bool Sorters::descend(const int& a, const int& b)
{
    return b < a;
}

void Vector::sort(bool(*predicate)(const int& a, const int& b))
{
   
}



