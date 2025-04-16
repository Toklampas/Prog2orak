#include "sorter.h"

void Sorter::bubbleSort(Comparable** tomb, unsigned meret)
{
	for (unsigned i = 0; i < meret - 1; i++)
	{
		for (unsigned j = 0; j < i; i++)
		{
			if (tomb[j] < tomb[j - 1])
			{
				Comparable* temp = tomb[j];
				tomb[j] = tomb[j - 1];
				tomb[j - 1] = temp;
			}
		}
	}
}
