#pragma once

#include "THeap.h"

void pyramidSort(size_t size, int* array)
{
    THeap<int> heap(2, size, size, array);
    for (size_t i = 0; i < size; i++)
    {
        array[i] = heap.getMinKey();
        heap.removeMinKey();
    }
}