#include <iostream>

#include "TList.h"

int main()
{
	double b = 10;
	TList<int, double> tmp;
	//TNode<int, double> test(434, &b);
	tmp.InsertForward(111, 10.0);
	std::cout << tmp;
}