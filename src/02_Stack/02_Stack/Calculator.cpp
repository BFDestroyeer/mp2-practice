#pragma once

#include "Calculator.h"

void Calculator::ReadExpression(std::string input)
{
    std::string buffer; //Буфер ввода пермененной
    Stack<char> operators(input.length());  //Первый стек
    Stack<std::string> out(input.length()); //Второй стек
    expression = Stack<std::string>(input.length());
    variables = Dictionary(input.length());

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

        if (input[i] == ' ');
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

    while (!out.IsEmpty())
    {
        expression.Push(out.Pop());
    }
}

void Calculator::ReadDictionary()
{
    Stack<std::string> temp(expression);
    while (!temp.IsEmpty())
    {
        if ((temp.Top() != "+") && (temp.Top() != "-") && (temp.Top() != "*") && (temp.Top() != "/") && (variables.Count(temp.Top()) == 0))
        {
            bool isNumeric = true;
            for (unsigned i = 0; i < temp.Top().size(); i++)
            {
                if ((temp.Top()[i] < 48) || (temp.Top()[i] > 57)) isNumeric = false;
            }
            if (isNumeric)
            {
                variables.Push(temp.Top(), stoi(temp.Top()));
            }
            else
            {
                double input;
                std::cout << "Input " << temp.Top() << " ";
                std::cin >> input;
                variables.Push(temp.Top(), input);
            }
        }
        temp.Pop();
    }
}