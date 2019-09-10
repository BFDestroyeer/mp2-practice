#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TVector<double> a(4), b(4), c(4);
    std::cin >> a /*>> b*/;
    std::cout << a * -2;
    return 0;
}