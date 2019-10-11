#pragma once

#include <string>

#include "Dictionary.h"
#include "Stack.h"
#include "Exception.h"
#include "Functions.h"

static class Calculator
{
	static unsigned Priority(const char opr);

public:
    //Пробразовать к префиксонй форме
    static std::string ReadExpression(const std::string& input);
    //Запросить у пользователя значения пермеенных
    static Dictionary ReadDictionary(const std::string& input);
    //Вычислить выражение
	static double  Calculate(const std::string& input, const Dictionary variables);
};