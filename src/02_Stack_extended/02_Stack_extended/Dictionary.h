#pragma once

#include <string>

#include "Exception.h"

class Dictionary
{
    struct Element
    {
        std::string key;
        double value;
    };

    Element* values;
    size_t size;
    size_t head;

public:
    Dictionary(size_t size_ = 10);
    Dictionary(const Dictionary& temp);
    ~Dictionary();

    //���������� ��������
    void Push(const std::string& key_, double value_);

    //���������� ��������� � ����� ������
    unsigned Count(const std::string& key_) const;

    //���������� ������� �������� � ����� ������
    const double operator[](const std::string& key_) const;

    const Dictionary& operator=(const Dictionary& temp);
};