#pragma once
#include <limits.h>

class IntFifo
{

	int elementNum;
	int* pData;
public:
	IntFifo();
	IntFifo(const IntFifo& theOther);
	~IntFifo();	
	bool isEmpty() { if (elementNum == 0) return true; else return false; }
	bool get(int& element);
	void put(int element);
};

