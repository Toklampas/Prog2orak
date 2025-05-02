#include <limits.h>
#include "vector.h"

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	for (unsigned i = 0; i < v.elementNum; i++)
		os << ' ' << v.at(i);
	return os;
}

Vector::Vector(): elementNum(0), pData(nullptr) { }

Vector::Vector(const Vector& other): pData(nullptr)
{
	*this = other;
}

Vector::~Vector()
{
	delete[] pData;
}

unsigned Vector::size() const
{
	return elementNum;
}

void Vector::clear()
{
	delete[] pData;
	pData = nullptr;
	elementNum = 0;
}


bool Vector::erase(unsigned position)
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

int& Vector::at(unsigned position)
{
	return pData[position];
}

const int& Vector::at(unsigned position) const
{
	return pData[position];
}

bool Vector::insert(unsigned position, int element)
{
	if (elementNum == UINT_MAX)
		return false;

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
		for (unsigned i = 0; i<position; i++)
		{
			if (i < elementNum)
				pTemp[i] = pData[i];
			else
				pTemp[i] = 0;
		}

		pTemp[position] = element;
		elementNum = position + 1;
	}

	delete[] pData;
	pData = pTemp;

	return true;
}

int& Vector::operator[](unsigned position)
{
	return at(position);
}

const int& Vector::operator[](unsigned position) const
{
	return at(position);
}

const Vector& Vector::operator=(const Vector& other)
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
		pData = new int[elementNum];
		for (unsigned i = 0; i < elementNum; i++)
			pData[i] = other.pData[i];
	}

	return *this;
}