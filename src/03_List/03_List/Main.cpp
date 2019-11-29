#include <iostream>

#include "TPolynom.h"
#include "Exception.h"

int main()
{
	TPolynom first, second;
	char input;

	try
	{
		std::cout << "Enter first polynom:" << std::endl;
		std::cin >> first;
		std::cout << "Enter second polynom:" << std::endl;
		std::cin >> second;
	}
	catch (TException exept)
	{
		if (exept.type == UnexpectedChar)
			std::cout << "Wrong input form" << std::endl;
		if (exept.type == NotInSystem)
			std::cout << "Result is not in system" << std::endl;
		return -1;
	}

	std::cout << "Sum:" << std::endl;
	std::cout << first + second << std::endl;;
	std::cout << "Substraction" << std::endl;
	std::cout << first - second << std::endl;;
	std::cout << "Multiplication" << std::endl;
	try
	{
		std::cout << first * second << std::endl;
	}
	catch (TException exept)
	{
		if (exept.type == NotInSystem)
			std::cout << "Result is not in system" << std::endl;
	}
	system("pause");
}