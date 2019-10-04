#pragma once
#include <iostream>
#include <locale>

#include <string>

/*#include "Headers/Stack/Stack.h"
#include "Headers/Application/Application.h"*/

#include "Dictionary.h"
#include "Calculator.h"

int main()
{
    Calculator temp;
    temp.ReadExpression("A1+B1*(C1-D1)/(F1+E1)+K1");
    temp.ReadDictionary();
}