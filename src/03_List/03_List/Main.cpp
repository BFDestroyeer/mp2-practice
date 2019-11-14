#include <iostream>

#include "TPolynom.h"

int main()
{
	TPolynom a;
	float b = 10;
	TNode<int, float> test(3, &b);
	a + test;
	std::cout << *(a.list);
}