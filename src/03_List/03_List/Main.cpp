#include <iostream>

#include "TPolynom.h"
#include "Exception.h"

int main()
{
	TPolynom first, second;
	char input;

	std::cout << "Enter first polynom:" << std::endl;
	std::cin >> first;
	std::cout << "Enter second polynom:" << std::endl;
	std::cin >> second;

	std::cout << "Sum:" << std::endl;
	std::cout << first + second << std::endl;;
	std::cout << "Substraction" << std::endl;
	std::cout << first - second << std::endl;;
	std::cout << "Multiplication" << std::endl;
	std::cout << first * second << std::endl;
	system("pause");
}