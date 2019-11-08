#pragma once

#include <iostream>

#include "TList.h"
#include "TNode.h"

void TestTList()
{
	TList<int, int> list;
	int buffer = 10;

	std::cout << "Insert forward" << std::endl;
	list.InsertForward(1, &buffer);
	std::cout << list << std::endl;

	std::cout << "Insert backward" << std::endl;
	list.InsertBackward(2, &buffer);
	std::cout << list << std::endl;

	std::cout << "Insert before key 2" << std::endl;
	list.InsertBefore(2, 3, &buffer);
	std::cout << list << std::endl;

	std::cout << "Insert after key 3" << std::endl;
	list.InsertAfter(3, 4, &buffer);
	std::cout << list << std::endl;

	std::cout << "Construct copy" << std::endl;
	std::cout << TList<int, int>(list) << std::endl;
	
	std::cout << "Construct from node" << std::endl;
	std::cout << TList<int, int>(&TNode<int, int>(66, &buffer)) << std::endl;

	std::cout << "Print all keys using next() and isEnded()" << std::endl;
	while (!list.IsEnded())
	{
		std::cout << list.GetCurrentKey() << " ";
		list.Next();
	}
	list.Reset();
	std::cout << std::endl << std::endl;

	std::cout << "Remove element with key 2" << std::endl;
	list.Remove(2);
	std::cout << list << std::endl;

	std::cout << "Remove element with key 3" << std::endl;
	list.Remove(3);
	std::cout << list << std::endl;

	std::cout << "Remove element with key 1" << std::endl;
	list.Remove(1);
	std::cout << list << std::endl;
	
	std::cout << "Remove element with key 4" << std::endl;
	list.Remove(4);
	std::cout << list << std::endl;

	std::cout << "Is empty: ";
	if (list.IsEmpty())
	{
		std::cout << "YES" << std::endl << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl << std::endl;
	}
}