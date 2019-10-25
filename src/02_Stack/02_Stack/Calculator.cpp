#pragma once

#include "Calculator.h"

unsigned Calculator::Priority(const char opr)
{
	if ((opr == '*') || (opr == '/')) return 3;
	if ((opr == '+') || (opr == '-')) return 2;
	if (opr == ')') return 1;
	return 0;
}

std::string Calculator::ReadExpression(const std::string& input)
{
    std::string buffer; //Буфер ввода пермененной
    Stack<char> operators(input.length());  //Первый стек
    Stack<std::string> out(input.length()); //Второй стек

    //Переменные контроля корректности ввода
    int cOperand = 0, cOperator = 0, cLeftBraket = 0, cRightBracket = 0, cLastInputType = -1;

    for (int i = 0; i < input.size(); i++)
    {
        if (buffer.length() != 0)
        {
            if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/') || (input[i] == '(') || (input[i] == ')') || (input[i] == ' '))
            {
                out.Push(buffer);
                buffer.clear();
                cOperand++;
                if (cLastInputType == 0) throw Exception(BadExpression);
                cLastInputType = 0;
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
            cLeftBraket++;
            if ((cLastInputType == 0) || (cLastInputType == 3)) throw Exception(BadExpression);
            cLastInputType = 2;
        }
        else if (input[i] == ')')
        {
			cRightBracket++;
			if (cRightBracket > cLeftBraket) throw Exception(BadExpression);
            while (operators.Top() != '(') 
            {
                std::string temp;
                temp.push_back(operators.Top());
				operators.Pop();
                out.Push(temp);
            }
            operators.Pop();
            if (cLastInputType == 1) throw Exception(BadExpression);
            cLastInputType = 3;
        }
        else if (operators.IsEmpty())
        {
            operators.Push(input[i]);
            cOperator++;
            if ((cLastInputType == 1) || (cLastInputType == 2)) throw Exception(BadExpression);
            cLastInputType = 1;
        }
        else if (Priority(input[i]) > Priority(operators.Top()))
        {
            operators.Push(input[i]);
            cOperator++;
            if ((cLastInputType == 1) || (cLastInputType == 2)) throw Exception(BadExpression);
            cLastInputType = 1;
        }
        else
        {
            while ((!operators.IsEmpty()) && (operators.Top() != '(') && (Priority(input[i]) <= Priority(operators.Top())))
            {
                std::string temp;
                temp.push_back(operators.Top());
				operators.Pop();
                out.Push(temp);
            }
            operators.Push(input[i]);
            cOperator++;
            if ((cLastInputType == 1) || (cLastInputType == 2)) throw Exception(BadExpression);
            cLastInputType = 1;
        }
    }

    if (buffer.length() != 0)
    {
        out.Push(buffer);
        buffer.clear();
        cOperand++;
        cLastInputType = 0;
    }

    if ((cOperand != cOperator + 1) || (cLeftBraket != cRightBracket)) throw Exception(BadExpression);

    while (!operators.IsEmpty())
    {
        std::string temp;
        temp.push_back(operators.Top());
		operators.Pop();
        out.Push(temp);
    }

    std::string expression;
    while (!out.IsEmpty())
    {
        expression.insert(0, " ");
        expression.insert(0, out.Top());
		out.Pop();
    }
    return expression;
}

Dictionary Calculator::ReadDictionary(const std::string& input)
{
    std::string buffer;
    Dictionary out;

    for (unsigned i = 0; i < input.size(); i++)
    {
        if ((input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/') && (input[i] != ' '))
        {
            buffer.push_back(input[i]);
        }
		else if (out.Count(buffer) != 0)
		{
			buffer.clear();
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
    Stack<double> result(input.length());
    std::string buffer;

    for (unsigned i = 0; i < input.size(); i++)
    {
        
        if ((input[i] != ' ') && (input[i] != '+') && (input[i] != '-') && (input[i] != '*') && (input[i] != '/'))
        {
            buffer.push_back(input[i]);
        }
        else
        {
            if (buffer.size() != 0)
            {
                result.Push(variables[buffer]);
				buffer.clear();
            }
            if (input[i] == '+')
            {
                double b = result.Top();
				result.Pop();
                double a = result.Top();
				result.Pop();
                result.Push(a + b);
            }
            else if (input[i] == '-')
            {
                double b = result.Top();
				result.Pop();
                double a = result.Top();
				result.Pop();
                result.Push(a - b);
            }
            else if (input[i] == '*')
            {
                double b = result.Top();
				result.Pop();
                double a = result.Top();
				result.Pop();
                result.Push(a * b);
            }
            else if (input[i] == '/')
            {
                double b = result.Top();
				result.Pop();
                double a = result.Top();
				result.Pop();
                if (b == 0) throw Exception(DivizionByZero);
                result.Push(a / b);
            }
        }
    }
    return result.Top();
}