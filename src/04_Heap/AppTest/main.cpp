#include <iostream>

#include "pyramidSort.h"

int main()
{
    int array[5] = { 3, 4, 5, 1, 2 };

    pyramidSort(5, array);
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i];
    }
    system("pause");
}