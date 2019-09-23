#pragma once
#include <iostream>

#include "Headers/Stack/Stack.h"
#include "Headers/Application/Application.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Application<double> a;
    a.Read();
    a.ReadDictionary();
    std::cout << a.Calculate();
}