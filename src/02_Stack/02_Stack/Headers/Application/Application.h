#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../Stack/Stack.h"
#include "../../Functions/Functions.h"

template <typename ValueType>
class Application
{
protected:
    std::map<std::string, ValueType> dictionary;    //Словарь соответсвия переменных и чисел
    std::vector<std::string> expression;                  //Математическое выражение

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
    std::string bufer;
    std::cout << "Введите выражение" << std::endl;
    std::getline(std::cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        
        if (input[i] == ' ')
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
        }
        else if ((input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/') && (input[i] != '(') && (input[i] != ')'))
        {
            bufer.push_back(input[i]);
        }
        else if (input[i] == '(')
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
            operators.Push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
            while (operators.Top() != '(')
            {
                std::string temp;
                temp.push_back(operators.Pop());
                expression.push_back(temp);
            }
            operators.Pop();
        }
        else if ((operators.IsEmpty()) || (operators.Top() == '('))
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
            operators.Push(input[i]);
        }
        else if (Functions::Priority(input[i]) > Functions::Priority(operators.Top()))
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
            operators.Push(input[i]);
        }
        else
        {
            if (bufer.length() != 0)
            {
                expression.push_back(bufer);
                bufer.clear();
            }
            while ((!operators.IsEmpty()) &&(operators.Top() != '(') && (Functions::Priority(input[i]) <= Functions::Priority(operators.Top())))
            {
                std::string temp;
                temp.push_back(operators.Pop());
                expression.push_back(temp);
            }
            operators.Push(input[i]);
        }
    }
    if (bufer.length() != 0)
    {
        expression.push_back(bufer);
        bufer.clear();
    }
    while (!operators.IsEmpty())
    {
        std::string temp;
        temp.push_back(operators.Pop());
        expression.push_back(temp);
    }
}

template <typename ValueType>
void Application<ValueType>::ReadDictionary()
{
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if ((expression[i] != "+") && (expression[i] != "-") && (expression[i] != "*") && (expression[i] != "/"))
        {
            if (dictionary.count(expression[i]) == 0)
            {
                bool isNumeric = true;
                for (unsigned j = 0; j < expression[i].length(); j++)
                {
                    if ((expression[i][j] < 48) || (expression[i][j] > 57)) isNumeric = false;
                }
                if (isNumeric)
                {
                    unsigned multiply = 1;
                    ValueType value = 0;
                    for (unsigned j = 0; j < expression[i].length(); j++)
                    {
                        value += (expression[i][expression[i].length() - 1 - j] - 48) * multiply;
                        multiply *= 10;
                    }
                    dictionary.insert(std::pair<std::string, ValueType>(expression[i], value));
                }
                else
                {
                    ValueType input;
                    std::cout << "Введите значение переменной " << expression[i] << " ";
                    std::cin >> input;
                    dictionary.insert(std::pair<std::string, ValueType>(expression[i], input));
                }
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
        if ((expression[i] != "+") && (expression[i] != "-") && (expression[i] != "*") && (expression[i] != "/"))
        {
            result.Push(dictionary[expression[i]]);
        }
        else if (expression[i] == "+")
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a + b);
        }
        else if (expression[i] == "-")
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a - b);
        }
        else if (expression[i] == "*")
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            result.Push(a * b);
        }
        else if (expression[i] == "/")
        {
            ValueType b = result.Pop();
            ValueType a = result.Pop();
            if (b == 0) throw "Divizion by zero";
            result.Push(a / b);
        }
    }
    return result.Top();
}