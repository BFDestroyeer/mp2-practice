#pragma once

#include "Calculator.h"

std::string Calculator::ReadExpression(const std::string& input)
{
    std::string buffer; //Буфер ввода пермененной
    Stack<char> operators(input.length());  //Первый стек
    Stack<std::string> out(input.length()); //Второй стек

    for (int i = 0; i < input.size(); i++)
    {
        if (buffer.length() != 0)
        {
            if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/') || (input[i] == '(') || (input[i] == ')') || (input[i] == ' '))
            {
                out.Push(buffer);
                buffer.clear();
            }
        }

        if (input[i] == ' ')
        {

        }
        else if ((input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/') && (input[i] != '(') && (input[i] != ')'))
        {
            buffer.push_back(input[i]);
        }
        else if (input[i] == '(')
        {
            operators.Push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (operators.Top() != '(')
            {
                std::string temp;
                temp.push_back(operators.Pop());
                out.Push(temp);
            }
            operators.Pop();
        }
        else if (operators.IsEmpty())
        {
            operators.Push(input[i]);
        }
        else if (Priority(input[i]) > Priority(operators.Top()))
        {
            operators.Push(input[i]);
        }
        else
        {
            while ((!operators.IsEmpty()) && (operators.Top() != '(') && (Priority(input[i]) <= Priority(operators.Top())))
            {
                std::string temp;
                temp.push_back(operators.Pop());
                out.Push(temp);
            }
            operators.Push(input[i]);
        }
    }

    if (buffer.length() != 0)
    {
        out.Push(buffer);
        buffer.clear();
    }

    while (!operators.IsEmpty())
    {
        std::string temp;
        temp.push_back(operators.Pop());
        out.Push(temp);
    }

    std::string expression;
    while (!out.IsEmpty())
    {
        expression.insert(0, " ");
        expression.insert(0, out.Pop());
    }
    return expression;
}

Dictionary Calculator::ReadDictionary(const std::string& input)
{
    std::string buffer;
    Dictionary out(100);

    for (unsigned i = 0; i < input.size(); i++)
    {
        if ((input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/') && (input[i] != ' '))
        {
            buffer.push_back(input[i]);
        }
        else if (buffer.size() != 0)
        {
            bool isNumeric = true;
            for (unsigned j = 0; j < buffer.size(); j++)
            {
                if ((buffer[j] < 48) || (buffer[j] > 57)) isNumeric = false;
            }
            if (isNumeric)
            {
                out.Push(buffer, stoi(buffer));
            }
            else
            {
                double inputVariable;
                std::cout << "Input " << buffer << " ";
                std::cin >> inputVariable;
                out.Push(buffer, inputVariable);
            }
            buffer.clear();
        }
    }
    return out;
}

double Calculator::Calculate(const std::string& input, const Dictionary variables)
{
    Stack<double> result(100);
    std::string buffer;

    for (unsigned i = 0; i < input.size(); i++)
    {
        
        if (input[i] != ' ')
        {
            buffer.push_back(input[i]);
        }
        else
        {
            if ((buffer != "+") && (buffer != "-") && (buffer != "*") && (buffer != "/"))
            {
                result.Push(variables[buffer]);
            }
            else if (buffer == "+")
            {
                double b = result.Pop();
                double a = result.Pop();
                result.Push(a + b);
            }
            else if (buffer == "-")
            {
                double b = result.Pop();
                double a = result.Pop();
                result.Push(a - b);
            }
            else if (buffer == "*")
            {
                double b = result.Pop();
                double a = result.Pop();
                result.Push(a * b);
            }
            else if (buffer == "/")
            {
                double b = result.Pop();
                double a = result.Pop();
                if (b == 0) throw "Divizion by zero";
                result.Push(a / b);
            }
            buffer.clear();
        }
    }
    return result.Top();
}