#pragma once

enum Exception_Type
{
    BadExpression,  //Неправильное выражение  
    DivizionByZero  //Деление на 0
};

struct Exception
{
    Exception_Type type;

    Exception(Exception_Type type_)
    {
        type = type_;
    }
};