#pragma once

#include "Dictionary.h"

Dictionary::Dictionary(size_t size_)
{
    size = size_;
    head = 0;
    values = new Element[size];
}

Dictionary::Dictionary(const Dictionary& temp)
{
    size = temp.size;
    head = temp.head;
    values = new Element[size];
    for (size_t i = 0; i < head; i++)
    {
        values[i] = temp.values[i];
    }
}

Dictionary::~Dictionary()
{
    delete[] values;
}

void Dictionary::Push(const std::string& key_, double value_)
{
    if (head == size) return;
    values[head].key = key_;
    values[head].value = value_;
    head++;
}

unsigned Dictionary::Count(const std::string& key_) const
{
    unsigned result = 0;
    for (size_t i = 0; i < head; i++)
    {
        if (values[i].key == key_) result++;
    }
    return result;
}

const double Dictionary::operator[](const std::string& key_) const
{
    for (size_t i = 0; i < head; i++)
    {
        if (values[i].key == key_) return values[i].value;
    }
    throw "NotFind";
}

const Dictionary& Dictionary::operator=(const Dictionary& temp)
{
    if (size != temp.size) delete[] values;
    size = temp.size;
    head = temp.head;
    values = new Element[size];
    for (size_t i = 0; i < head; i++)
    {
        values[i] = temp.values[i];
    }
    return *this;
}