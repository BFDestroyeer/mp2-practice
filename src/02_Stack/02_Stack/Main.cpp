#pragma once
#include <iostream>
#include <locale>
#include <string>

#include "Dictionary.h"
#include "Calculator.h"

int main()
{
    Calculator temp;
    std::string input;
    std::getline(std::cin, input);
    temp.ReadExpression(input);
    temp.ReadDictionary();
    std::cout << temp.Calculate();
}