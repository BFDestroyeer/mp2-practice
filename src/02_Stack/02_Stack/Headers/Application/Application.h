#pragma once
#include <iostream>
#include <map>
#include <string>

template <typename ValueType>
class Application
{
public:
//protected:
    std::map<char, ValueType> dictionary;    //������� ����������� ���������� � �����
    std::string expression;                  //�������������� ���������

public:
    Application();
    Application(const Application& temp);
    ~Application();

    void Read();              //������ ���������
    void ReadDictionary();    //������ �������
    ValueType Calculate();    //���������� ��������
};

template <typename ValueType>
Application<ValueType>::Application()
{
    for (int i = 0; i < 10; i++)
    {
        dictionary.insert(std::pair<char, ValueType>((char) 30 + i, i));
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

}

template <typename ValueType>
void Application<ValueType>::ReadDictionary()
{
    for (unsigned i = 0; i < expression.size; i++)
    {
        if ((expression[i] != '+') && (expression[i] != '-') && (expression[i] != '*') && (expression[i] != '/'))
        {
            if (dictionary.count(expression[i]) == 0)
            {

            }
        }
    }
}

template <typename ValueType>
ValueType Application<ValueType>::Calculate()
{
    return 0;
}