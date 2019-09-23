#pragma once
#include <iostream>

#include "Headers/Stack/Stack.h"
#include "Headers/Application/Application.h"

int main()
{
    Application<double> a;
    std::cout << a.dictionary.count('h');
}