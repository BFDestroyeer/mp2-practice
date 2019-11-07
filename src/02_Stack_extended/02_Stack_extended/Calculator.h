#pragma once

#include <iostream>
#include <string>

#include "Dictionary.h"
#include "Stack.h"
#include "ArrayStack.h"
#include "Exception.h"

class Calculator
{
	//Стеки
	Stack<char>* operators;
	Stack<std::string>* out;
	Stack<double>* result;

public:
	Calculator(int mode = 0);
	~Calculator();

private:
	static unsigned Priority(const char opr);

public:
    //Пробразовать к префиксонй форме
    std::string ReadExpression(const std::string& input);
    //Запросить у пользователя значения пермеенных
    Dictionary ReadDictionary(const std::string& input);
    //Вычислить выражение
    double Calculate(const std::string& input, const Dictionary variables);
};