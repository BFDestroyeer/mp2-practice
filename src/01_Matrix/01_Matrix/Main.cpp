#pragma once

#include <iostream>

#include "Headers/TVector/TVector.h"
#include "Headers/TVector/TMatrix/TMatrix.h"

int main()
{
    TMatrix<double> a(4), b(4);
    double c;
    TVector<double> d(4);

    setlocale(LC_ALL, "Russian");

    std::cout << "��������� ��������� ������� ������� ����������� �������" << std::endl;
    std::cout << "2019 ���. ��� ����� ��������" << std::endl;

    std::cout << std::endl << "������� �������� A, ������� 4" << std::endl;
    std::cin >> a;
    std::cout << "������� �������� B, ������� 4" << std::endl;
    std::cin >> b;
    std::cout << "������� ��������� c" << std::endl;
    std::cin >> c;
    std::cout << "������� ������ d, ������� 4" << std::endl;
    std::cin >> d;

    std::cout << std::endl << "�������� �������������" << std::endl;
    std::cout << "����������� � �����������" << std::endl;
    std::cout << TMatrix<double>(4) << std::endl;
    std::cout << "����������� �����������" << std::endl;
    std::cout << TMatrix<double>(a) << std::endl;
    /*std::cout << "����������� �������������� ����" << std::endl;
    std::cout << TMatrix<double>(TVector<TVector<double> >(4)) << std::endl;*/

    std::cout << "�������� ���������" << std::endl;
    std::cout << "A == B " << (a == b) << std::endl;
    std::cout << "A != B " << (a != b) << std::endl;

    std::cout << std::endl << "��������� ��������" << std::endl;
    std::cout << "A + c" << std::endl;
    std::cout << (a + c) << std::endl;
    std::cout << "A - c" << std::endl;
    std::cout << (a - c) << std::endl;
    std::cout << "A * c" << std::endl;
    std::cout << (a * c) << std::endl;

    std::cout << "��������� ��������" << std::endl;
    std::cout << "A+B" << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << "A-B" << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << "A*B" << std::endl;
    std::cout << (a * b) << std::endl;

    std::cout << "�������� ��������� �� ������" << std::endl;
    std::cout << "A*d" << std::endl;
    std::cout << (a * d) << std::endl;

    std::cout << std::endl << "�������� ������������" << std::endl;
    std::cout << (TMatrix<double>() = a) << std::endl;

    std::cout << "���������� ������������" << std::endl;
    std::cout << a.Determinant() << std::endl;

    std::cout << std::endl << "�������� ����������" << std::endl;
    try
    {
        a * TMatrix<double>(5);
    }
    catch (TException testException)
    {
        std::cout << "BadSize ������ �������" << std::endl;
    }
    try
    {
        a[10];
    }
    catch (TException testException)
    {
        std::cout << "BadIndex ������ �������" << std::endl;
    }
    try
    {
        a[3][0] = 1;
    }
    catch (TException testException)
    {
        std::cout << "WriteOnReadOnly ������ �������" << std::endl;
    }
}