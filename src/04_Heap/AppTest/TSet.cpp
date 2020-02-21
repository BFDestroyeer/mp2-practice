#include "TSet.h"

TSet::TSet(size_t size_ = 10)
{
    size = size_;
    array = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        array[i] = -1;
    }
}

TSet::TSet(size_t size_, int* elements_)
{
    size = size_;
    for (size_t i = 0; i < size; i++)
    {
        array[i] = elements_[i];
    }
}

TSet::~TSet()
{
    size = 0;
    delete[] array;
}

void TSet::createSubset(int id)
{
    if (array[id] != -1) throw "CANT";
    array[id] = id;
}

void TSet::uniteSubsets(int a, int b)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == b) array[i] = a;
    }
}

int TSet::getSubsetName(int id)
{
    return array[id];
}