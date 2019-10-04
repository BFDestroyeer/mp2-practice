#pragma once

enum Exception_Type
{
    BadSize,        //Неправльный размер матрицы или вектора
    BadIndex,       //Неправильный индекс
    WriteOnReadOnly, //Попытка записи в ячейку доступную только для чтения
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