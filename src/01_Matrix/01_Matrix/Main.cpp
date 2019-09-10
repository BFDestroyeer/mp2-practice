#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TVector<double> a(3), b(2, 1);
    std::cin >> a >> b;
    std::cout << (a*b);
    return 0;
}