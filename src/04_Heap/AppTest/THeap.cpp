#include "THeap.h"

THeap::THeap(unsigned d_, size_t max_size_)
{
    max_size = max_size_;
    d = d_;
    size = 0;
    array = new int[max_size];
}

THeap::~THeap()
{
    max_size = 0;
    d = 0;
    size = 0;
    delete[] array;
}

void THeap::Transpose(size_t a, size_t b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void THeap::moveUp(size_t id)
{
    int parent = (id - 1) / d;
    while (id > 0)
    {
        if (array[parent] > array[id])
        {
            Transpose(parent, id);
            id = parent;
        }
        else break;
    }
}

void THeap::moveDown(size_t id)
{
    current = getMinChild(id);
}

int THeap::getMinKey()
{

}

int THeap::getMinChild(size_t id)
{
    if (id * d + 1 <= size) throw "NoChilds";
    size_t a = id * d + 1;
    /*(size - 1) < (id * d + d);
    min = a;
    for (int i = a; a <= b; i++)
    {
        if (array[i] <= array[min]) min = i;
    }
    return min*/
}

void THeap::Heaping()
{

}