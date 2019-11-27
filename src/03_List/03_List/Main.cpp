#include <iostream>

#include "TPolynom.h"
#include "Exception.h"

int main()
{
	TPolynom test;
	TNode<int, double> node(100, 1), tnode(10, 1);
	test = test + node + tnode;
	TPolynom a(test);
	try
	{
		std::cout << test * test;
	}
	catch(TException)
	{
		std::cout << "AHTUNG";
	}
}