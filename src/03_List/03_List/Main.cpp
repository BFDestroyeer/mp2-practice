#include <iostream>

#include "TNode.h"

int main()
{
	double b = 10;
	TNode<int, double> test(3, &b);
	std::cout << test + test;
}