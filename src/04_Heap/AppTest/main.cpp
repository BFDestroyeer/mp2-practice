#include <iostream>

#include "pyramidSort.h"

#include "TKruskalsAlgorithm.h"

int main()
{
    /*int array[5] = { 3, 4, 5, 1, 2 };

    pyramidSort(5, array);
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i];
    }
    system("pause");*/

    TEdge a = { 1, 2, 1 }, b = { 2, 3, 1 }, c = { 1, 3, 1 };
    TGraph graph(3);
    graph.insertEdge(a);
    graph.insertEdge(b);
    graph.insertEdge(c);
    std::cout << TKruskalsAlgorithm::findTree(graph);
    system("pause");
}