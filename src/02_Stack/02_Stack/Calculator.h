#pragma once

#include <string>

#include "Dictionary.h"
#include "Stack.h"
#include "Exception.h"
#include "Functions.h"

namespace Calculator
{
    //Пробразовать к префиксонй форме
    std::string ReadExpression(const std::string& input);
    //Запросить у пользователя значения пермеенных
    Dictionary ReadDictionary(const std::string& input);
    //Вычислить выражение
    double Calculate(const std::string& input, const Dictionary variables);
};