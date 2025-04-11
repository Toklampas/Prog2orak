#include "vector.h"
// #define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}

Vector::Vector(const Vector& theOther)
{
    pData = nullptr;
    *this = theOther;
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

int& Vector::at(unsigned position)
{
    if (position >= 0 && position <= elementNum)
        return pData[position];
}

const int& Vector::at(unsigned position) const
{
    if (position >= 0 && position <= elementNum)
    {
        const int out = pData[position];
        return out;
    }
}

int& Vector::operator[](unsigned position)
{
    return at(position);
}

const int& Vector::operator[](unsigned position) const
{
    return at(position);
}

bool Sorters::ascend(const int& a, const int& b)
{
    return a < b;
}

bool Sorters::descend(const int& a, const int& b)
{
    return a > b;
}

void Vector::sort(bool(*predicate)(const int& a, const int& b))
{
    for (unsigned i = 0; i < elementNum - 1; i++)
    {
        unsigned minIndex = i;
        for (unsigned j = i + 1; j < elementNum; j++)
            if (predicate(pData[j], pData[minIndex]))
                minIndex = j;
        std::swap(pData[i], pData[minIndex]);
    }
}

Vector& Vector::operator=(const Vector& theOther)
{
    if (this == &theOther)
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
        pData = new int[elementNum];
        for (unsigned i = 0; i < elementNum; i++)
        {
            pData[i] = theOther.pData[i];
        }

    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    for (unsigned i = 0; i < v.elementNum; i++)
        os << v.pData[i] << " ";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v)
{

    for (int i = 0; i < v.maxElementsNum; i++)
    {

        int input;
        is >> input;
        if (is.good())
        {
            v.elementNum++;
            int* temp = new int[v.elementNum];

            if (v.pData)
                for (int j = 0; j < v.elementNum; j++)
                    temp[j] = v.pData[j];

            temp[i] = input;
            delete[] v.pData;
            v.pData = temp;
        }
        else
            return is;
    }
    return is;
}

void Vector::operator*=(unsigned right)
{
    if (pData == nullptr || elementNum == 0)
        return;
    else
    {
        for (unsigned i = 0; i < elementNum; i++)
            pData[i] *= right;
    }
}

void Vector::operator+=(unsigned right)
{
    if (pData == nullptr || elementNum == 0)
        return;
    else
    {
        for (unsigned i = 0; i < elementNum; i++)
            pData[i] += right;
    }
}