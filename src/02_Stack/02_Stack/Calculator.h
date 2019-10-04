#pragma once

#include <string>

#include "Dictionary.h"
#include "Headers/Stack/Stack.h"
#include "Functions/Functions.h"

class Calculator
{
protected:
    Stack<std::string> expression;
    Dictionary variables;

public:
    void ReadExpression(std::string input);
    void ReadDictionary();
    double Calculate();
};