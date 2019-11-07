#pragma once
#include <iostream>
#include <locale>
#include <string>

#include "Dictionary.h"
#include "Calculator.h"

int main()
{
    std::string input;
    std::string prefix;
    Dictionary dict;
	Calculator calulator;
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