#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TMatrix<double> a(3), b(3);
    TVector<double> c(3);
    std::cin >> a /*>> b*/;
    std::cout << a.Determinant();
    return 0;
}