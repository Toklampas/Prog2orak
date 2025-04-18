#include "sorter.h"

void Sorter::bubbleSort(Comparable** tomb, unsigned meret)
{
    for (unsigned i = 0; i < meret - 1; i++)
    {
        for (unsigned j = 0; j < meret - i - 1; j++)
        {
            if (*tomb[j + 1] < *tomb[j])
            {
                Comparable* temp = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = temp;
            }
        }
    }
}
