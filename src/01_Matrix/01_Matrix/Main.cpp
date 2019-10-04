#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    unsigned size;

    setlocale(LC_ALL, "Russian");

    std::cout << "Программа провекрки шаблона верхней треугольной матрицы" << std::endl;
    std::cout << "2019 год. Все права защищены" << std::endl;

    std::cout << std::endl << "Введите размер матриц ";
    std::cin >> size;

    TMatrix<double> a(size), b(size);
    double c;
    TVector<double> d(size);

    std::cout << "Введите матриицу A, размера " << size <<std::endl;
    std::cin >> a;
    std::cout << "Введите матриицу B, размера " << size <<std::endl;
    std::cin >> b;
    std::cout << "Введите константу c" << std::endl;
    std::cin >> c;
    std::cout << "Введите вектор d, размера " << size << std::endl;
    std::cin >> d;

    std::cout << std::endl << "Проверка конструкторов" << std::endl;
    std::cout << "Конструктор с параметрами" << std::endl;
    std::cout << TMatrix<double>(size) << std::endl;
    std::cout << "Конструктор копирования" << std::endl;
    std::cout << TMatrix<double>(a) << std::endl;
    /*std::cout << "Конструктор преобразования типа" << std::endl;
    std::cout << TMatrix<double>(Generate::VectorOfVectors(size)) << std::endl;*/

    std::cout << "Операции сравнения" << std::endl;
    std::cout << "A == B " << (a == b) << std::endl;
    std::cout << "A != B " << (a != b) << std::endl;

    std::cout << std::endl << "Скалярные операции" << std::endl;
    std::cout << "A + c" << std::endl;
    std::cout << (a + c) << std::endl;
    std::cout << "A - c" << std::endl;
    std::cout << (a - c) << std::endl;
    std::cout << "A * c" << std::endl;
    std::cout << (a * c) << std::endl;

    std::cout << "Матричные операции" << std::endl;
    std::cout << "A+B" << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << "A-B" << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << "A*B" << std::endl;
    std::cout << (a * b) << std::endl;

    std::cout << "Операция умножения на вектор" << std::endl;
    std::cout << "A*d" << std::endl;
    std::cout << (a * d) << std::endl;

    std::cout << std::endl << "Операция присваивания" << std::endl;
    std::cout << (TMatrix<double>() = a) << std::endl;

    std::cout << "Нахождение определителя" << std::endl;
    std::cout << a.Determinant() << std::endl;

    std::cout << std::endl << "Проверка исключений" << std::endl;
    try
    {
        a * TMatrix<double>(5);
    }
    catch (TException)
    {
        std::cout << "BadSize брошен успешно" << std::endl;
    }
    try
    {
        a[10];
    }
    catch (TException)
    {
        std::cout << "BadIndex брошен успешно" << std::endl;
    }
    try
    {
        a[3][0] = 1;
    }
    catch (TException)
    {
        std::cout << "WriteOnReadOnly брошен успешно" << std::endl;
    }
}