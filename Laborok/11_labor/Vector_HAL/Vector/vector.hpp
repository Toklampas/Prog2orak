#pragma once
#include <iostream>

// Egy dinamikus tömb osztály.
template <typename T>
class Vector
{
    // A tömb mérete.
    unsigned elementNum;

    // Az adatokra mutató pointer.
    T* pData;

    // Diagnosztikai célú globális kiiratóoperátor.
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const Vector<U>&);

public:
    // Konstruktorok, destruktor.
    Vector() : elementNum(0), pData(nullptr) {}
    Vector(const Vector& other) : pData(nullptr) { *this = other; }
    ~Vector() { delete[] pData; }

    // Visszatér a tömb méretével.
    unsigned size() const { return elementNum; }

    // Törli a tömböt.
    void clear()
    {
        delete[] pData;
        pData = nullptr;
        elementNum = 0;
    }

    // Törli a megadott indexű elemet. A 0 és size()-1 közötti indexek érvényesek.
    // Igazzal tér vissza, ha sikeres a törlés, különben hamissal.
    bool erase(unsigned position)
    {
        if (position >= elementNum)
            return false;

        if (elementNum == 1)
        {
            delete[] pData;
            pData = nullptr;
            elementNum = 0;
            return true;
        }

        T* pTemp = new T[--elementNum];

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

    // Visszatér a megadott indexu elemmel, amely módosítható is egyben.
    // A 0 és size()-1 közötti indexek érvényesek.
    T& at(unsigned position) { return pData[position]; }

    // Visszatér a megadott indexu elemmel, amely csak olvasható.
    // A 0 és size()-1 közötti indexek érvényesek.
    const T& at(unsigned position) const { return pData[position]; }

    // Beszúr egy elemet a megadott indexű helyre. 
    // Ha az index nagyobb, mint a tömb mérete, megnöveli a tömb méretét, 
    // és a szükséges új helyeket nullákkal tölti fel.
    bool insert(unsigned position, const T& element)
    {
        if (elementNum == std::numeric_limits<unsigned>::max())
            return false;

        T* pTemp = nullptr;
        if (position < elementNum)
        {
            pTemp = new T[elementNum + 1];
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
            pTemp = new T[position + 1];
            for (unsigned i = 0; i < position; i++)
            {
                if (i < elementNum)
                    pTemp[i] = pData[i];
                else
                    pTemp[i] = T();
            }

            pTemp[position] = element;
            elementNum = position + 1;
        }

        delete[] pData;
        pData = pTemp;

        return true;
    }

    // A bal oldali vektort felülírja a jobb oldalival.
    const Vector& operator=(const Vector& other)
    {
        if (this == &other)
            return *this;

        delete[] pData;

        if (!other.elementNum)
        {
            elementNum = 0;
            pData = nullptr;
        }
        else
        {
            elementNum = other.elementNum;
            pData = new T[elementNum];
            for (unsigned i = 0; i < elementNum; i++)
                pData[i] = other.pData[i];
        }

        return *this;
    }

    // Két operator[]. Az at() tagfüggvény operator formában is.
    T& operator[](unsigned position) { return at(position); }
    const T& operator[](unsigned position) const { return at(position); }
};

// Diagnosztikai célú kiiratás.
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
    for (unsigned i = 0; i < v.elementNum; i++)
        os << ' ' << v.at(i);
    return os;
}