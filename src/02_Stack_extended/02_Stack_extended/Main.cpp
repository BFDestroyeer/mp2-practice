#pragma once
#include <iostream>
#include <locale>
#include <string>

#include "Dictionary.h"
#include "Calculator.h"

#include "TestTList.h"

int main()
{
	TestTList();

    std::string input;
    std::string prefix;
    Dictionary dict;
	int mode;
	std::cout << "Which stack use?" << std::endl;
	std::cout << "0 ArrayStack" << std::endl;
	std::cout << "1 ListStack" << std::endl;
	std::cin >> mode;
	Calculator calulator(mode);
	getchar();
	system("cls");
    std::cout << "Please, input expression" << std::endl;
    std::getline(std::cin, input);
    try
    {
        prefix = calulator.ReadExpression(input);
        std::cout << "Your expression in prefix form:" << std::endl  << prefix << std::endl;
        dict = calulator.ReadDictionary(prefix);
		std::cout << "Result: " << calulator.Calculate(prefix, dict) << std::endl;
    }
    catch (Exception exp)
    {
        if (exp.type == DivizionByZero)
        {
            std::cout << "Can't divide by zero" << std::endl;
        }
        else
        {
            std::cout << "Bad expression" << std::endl;
        }
    }
	system("pause");
}