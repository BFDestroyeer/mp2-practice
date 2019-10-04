#pragma once

enum Exception_Type
{
    BadSize,        //Неправльный размер матрицы или вектора
    BadIndex,       //Неправильный индекс
    CantCreateEmpty,
    CantConvert
};

struct TException
{
    Exception_Type type;

    TException(Exception_Type type_)
    {
        type = type_;
    }
};