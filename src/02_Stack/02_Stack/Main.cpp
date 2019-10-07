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
    std::getline(std::cin, input);
    prefix = Calculator::ReadExpression(input);
    dict = Calculator::ReadDictionary(prefix);
    std::cout << Calculator::Calculate(prefix, dict);
}