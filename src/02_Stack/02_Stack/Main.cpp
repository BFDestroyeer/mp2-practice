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
    std::cout << "Please, input expression" << std::endl;
    std::getline(std::cin, input);
    try
    {
        prefix = Calculator::ReadExpression(input);
        std::cout << "Your expression in prefix form:" << std::endl  << prefix << std::endl;
        dict = Calculator::ReadDictionary(prefix);
        std::cout << "Result: "<< Calculator::Calculate(prefix, dict);
    }
    catch (Exception exp)
    {
        if (exp.type == DivizionByZero)
        {
            std::cout << "Can't divide by zero";
        }
        else
        {
            std::cout << "Bad expression";
        }
    }
}