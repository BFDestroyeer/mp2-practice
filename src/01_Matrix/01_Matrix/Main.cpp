#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TMatrix<double> a(2), b(2);
    TVector<double> c(2);
    std::cin >> a >> b;
    a = a - b;
    std::cout << a;
    return 0;
}