#include <iostream>

#include "TPolynom.h"

int main()
{
	TPolynom test;
	TNode<int, double> node(123, 10), tnode(124, 5);
	test = test + node;
	test = test + node;
	std::cout << test;
}