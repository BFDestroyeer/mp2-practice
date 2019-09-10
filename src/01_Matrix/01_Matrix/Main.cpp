#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TVector<double> a(4), b(4);
    a = a + b;
    std::cin >> a;
    //std::cout << std::endl;
    return 0;
}