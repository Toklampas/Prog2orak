#include "IntFifo.h"



IntFifo::IntFifo()
{
	elementNum = 0;
	pData = nullptr;
}

IntFifo::IntFifo(const IntFifo& theOther) {
		if (theOther.elementNum == 0)
	{
		pData = nullptr;
		elementNum = 0;
	}
	else {
		elementNum = theOther.elementNum;

		pData = new int[elementNum];
		for (int i = 0; i < elementNum; i++)
		{
			pData[i] = theOther.pData[i];
		}
	}
}

IntFifo::~IntFifo()
{
	delete[] pData;
}

bool IntFifo::get(int & element)
{
	if(elementNum==0)
		return false;
	if (elementNum == 1)
	{
		element = pData[0];
		elementNum = 0;
		delete[] pData;
		pData = nullptr;
		return true;
	}
	elementNum--;
	element = pData[0];
	int* pTemp = new int[elementNum];
	for (int i = 0; i < elementNum; i++)
	{
		pTemp[i] = pData[i+1];
	}
	delete[] pData;
	pData = pTemp;
	return true;
}

void IntFifo::put(int element)
{
	int* pTemp = new int[elementNum + 1];
	for (int i = 0; i < elementNum; i++)
	{
		pTemp[i] = pData[i];
	}
	pTemp[elementNum++] = element;
	delete[] pData;
	pData = pTemp;
	return true;
}
