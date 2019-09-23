#pragma once
#include <iostream>
#include <map>
#include <string>

#include "../Stack/Stack.h"
#include "../../Functions/Functions.h"

template <typename ValueType>
class Application
{
public:
//protected:
    std::map<char, ValueType> dictionary;    //Словарь соответсвия переменных и чисел
    std::string expression;                  //Математическое выражение

public:
    Application();
    Application(const Application& temp);
    ~Application();

    void Read();              //Чтение выражения
    void ReadDictionary();    //Чтение словаря
    ValueType Calculate();    //Вычисление значения
};

template <typename ValueType>
Application<ValueType>::Application()
{
    for (int i = 0; i < 10; i++)
    {
        dictionary.insert(std::pair<char, ValueType>((char) 48 + i, i));
    }
}

template <typename ValueType>
Application<ValueType>::Application(const Application& temp)
{
    dictionary = temp.dictionary;
    expression = temp.expression;
}

template <typename ValueType>
Application<ValueType>::~Application()
{
    dictionary.clear();
    expression.clear();
}

template <typename ValueType>
void Application<ValueType>::Read()
{
    Stack<char> operators;
    std::string input;
    std::cout << "Введите выражение" << std::endl;
    //std::cin >> input;
    std::getline(std::cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            ;
        }
        else if ((input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/') && (input[i] != '(') && (input[i] != ')'))
        {
            expression.push_back(input[i]);
        }
        else if (input[i] == '(')
        {
            operators.Push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (operators.Top() != '(')
            {
                expression.push_back(operators.Pop());
            }
            operators.Pop();
        }
        else if ((operators.IsEmpty()) || (operators.Top() == '('))
        {
            operators.Push(input[i]);
        }
        else if (Functions::Priority(input[i]) > Functions::Priority(operators.Top()))
        {
            operators.Push(input[i]);
        }
        else
        {
            while ((!operators.IsEmpty()) &&(operators.Top() != '(') && (Functions::Priority(input[i]) <= Functions::Priority(operators.Top())))
            {
                expression.push_back(operators.Pop());
            }
            operators.Push(input[i]);
        }
    }
    while (!operators.IsEmpty())
    {
        expression.push_back(operators.Pop());
    }
}

template <typename ValueType>
void Application<ValueType>::ReadDictionary()
{
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if ((expression[i] != '+') && (expression[i] != '-') && (expression[i] != '*') && (expression[i] != '/'))
        {
            if (dictionary.count(expression[i]) == 0)
            {
                ValueType input;
                std::cout << "Введите значение переменной " << expression[i] << " ";
                std::cin >> input;
                dictionary.insert(std::pair<char, ValueType>(expression[i], input));
            }
        }
    }
}

template <typename ValueType>
ValueType Application<ValueType>::Calculate()
{
    Stack<ValueType> result;
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if ((expression[i] != '+') && (expression[i] != '-') && (expression[i] != '*') && (expression[i] != '/'))
        {
            result.Push(dictionary[expression[i]]);
        }
        else if (expression[i] == '+')
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a + b);
        }
        else if (expression[i] == '-')
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a - b);
        }
        else if (expression[i] == '*')
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a * b);
        }
        else if (expression[i] == '/')
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            if (b == 0) throw "Divizion by zero";
            result.Push(a / b);
        }
    }
    return result.Top();
}