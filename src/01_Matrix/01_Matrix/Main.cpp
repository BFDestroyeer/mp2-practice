#pragma once

#include <iostream>
#include <locale>

#include "TVector.h"
#include "TMatrix.h"
#include "Generate.h"

int main()
{
    unsigned sizeA, sizeB, sizeD;

    setlocale(LC_ALL, "Russian");

    std::cout << "Программа провекрки шаблона верхней треугольной матрицы" << std::endl;
    std::cout << "2019 год. Все права защищены" << std::endl;

    std::cout << std::endl << "Введите размер матрицы A ";
    std::cin >> sizeA;
    std::cout << "Введите размер матрицы B ";
    std::cin >> sizeB;
    std::cout << "Введите размер вектора D ";
    std::cin >> sizeD;

    TMatrix<double> a(sizeA), b(sizeB);
    double c;
    TVector<double> d(sizeD);

    std::cout << "Введите матриицу A, размера " << sizeA <<std::endl;
    std::cin >> a;
    std::cout << "Введите матриицу B, размера " << sizeB <<std::endl;
    std::cin >> b;
    std::cout << "Введите константу c" << std::endl;
    std::cin >> c;
    std::cout << "Введите вектор d, размера " << sizeD << std::endl;
    std::cin >> d;

    std::cout << std::endl << "Проверка конструкторов" << std::endl;
    std::cout << "Конструктор копирования" << std::endl;
    std::cout << TMatrix<double>(a) << std::endl;
    std::cout << "Конструктор преобразования типа" << std::endl;
    std::cout << TMatrix<double>(Generate::VectorOfVectors(sizeA)) << std::endl;

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
    try
    {
        std::cout << (a + b) << std::endl;
    }
    catch (TException)
    {
        std::cout << "BadSize брошен успешно" << std::endl;
    }
    std::cout << "A-B" << std::endl;
    try
    {
        std::cout << (a - b) << std::endl;
    }
    catch (TException)
    {
        std::cout << "BadSize брошен успешно" << std::endl;
    }
    std::cout << "A*B" << std::endl;
    try
    {
        std::cout << (a * b) << std::endl;
    }
    catch (TException)
    {
        std::cout << "BadSize брошен успешно" << std::endl;
    }

    std::cout << "Операция умножения на вектор" << std::endl;
    std::cout << "A*d" << std::endl;
    try
    {
        std::cout << (a * d) << std::endl;
    }
    catch (TException)
    {
        std::cout << "BadSize брошен успешно" << std::endl;
    }

    std::cout << std::endl << "Операция присваивания" << std::endl;
    std::cout << (TMatrix<double>() = a) << std::endl;

    std::cout << "Нахождение определителя" << std::endl;
    std::cout << a.Determinant() << std::endl;

    std::cout << std::endl << "Проверка особых исключений" << std::endl;
    try
    {
        std::cout << "Обращаюсь к недоступному полю" << std::endl;
        a[a.GetSize() + 1];
    }
    catch (TException)
    {
        std::cout << "BadIndex брошен успешно" << std::endl << std::endl;
    }
    try
    {
        std::cout << "Генерирую вектор нулевого размера" << std::endl;
        TVector<double> temp(0);
    }
    catch (TException)
    {
        std::cout << "Can't create empty брошен успешно" << std::endl << std::endl;
    }
    try
    {
        std::cout << "Преобразую неподходящую матрицу" << std::endl;
        TMatrix<double> temp(TVector<TVector<double> >(3));
    }
    catch (TException)
    {
        std::cout << "Can't convert брошен успешно" << std::endl;
    }
}