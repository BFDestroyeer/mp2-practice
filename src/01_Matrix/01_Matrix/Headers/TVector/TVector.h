#pragma once
#include <iostream>

#include "../TException/TExcepntion.h"

template <typename ValueType>
class TVector
{
protected:
    unsigned size;          //Размер вектора
    ValueType* elements;    //Данные
    unsigned startIndex;    //Начальный индекс 

public:
    TVector(unsigned size_ = 0, unsigned startIndex_ = 0);
    TVector(const TVector& temp);
    ~TVector();

    //Чтение полей
    unsigned GetSize() const;
    unsigned GetStartIndex() const;

    //Операции сравнения
    bool operator==(const TVector& temp) const;
    bool operator!=(const TVector& temp) const;

    //Скалярные операции
    TVector operator+(const ValueType& temp) const;
    TVector operator-(const ValueType& temp) const;
    TVector operator*(const ValueType& temp) const;

    //Векторные операции
    TVector operator+(const TVector& temp) const;
    TVector operator-(const TVector& temp) const;
    ValueType operator*(const TVector& temp) const;

    //Операция присваивания
    TVector& operator=(const TVector& temp);

    //Получение длинны(не размера) вектора
    ValueType Length() const;

    //Операции ввода-вывода в поток
    template <typename ValueType>
    friend std::ostream& operator<<(std::ostream& out, const TVector<ValueType>& vector);
    template <typename ValueType>
    friend std::istream& operator>>(std::istream& in, TVector<ValueType>& vector);

    //Операции индексации
    ValueType& operator[](unsigned index);
    const ValueType operator[](unsigned index) const;
};


template <typename ValueType>
TVector<ValueType>::TVector(unsigned size_, unsigned startIndex_)
{
    size = size_;
    startIndex = startIndex_;
    if (size) elements = new ValueType[size] else elements = nullptr;
    memset(elements, 0, size * sizeof(ValueType));
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector& temp)
{
    size = temp.size;
    startIndex = temp.startIndex;
    elements = new ValueType[size];
    memcpy(elements, temp.elements, size * sizeof(ValueType));
}

template <typename ValueType>
TVector<ValueType>::~TVector()
{
    if (elements != nullptr)
    {
        delete[] elements;
    }
}

//Чтение полей
template <typename ValueType>
unsigned TVector<ValueType>::GetSize() const
{
    return size;
}

template <typename ValueType>
unsigned TVector<ValueType>::GetStartIndex() const
{
    return startIndex;
}

//Операции сравнения
template <typename ValueType>
bool TVector<ValueType>::operator==(const TVector& temp) const
{
    if (elements == temp.elements) return true;
    if (size != temp.size) return false;
    for (unsigned i = 0; i < size; i++)
    {
        if (elements[i] != temp.elements[i]) return false;
    }
    return true;
}

template <typename ValueType>
bool TVector<ValueType>::operator!=(const TVector& temp) const
{
    if (elements == temp.elements) return false;
    if (size != temp.size) return true;
    for (unsigned i = 0; i < size; i++)
    {
        if (elements[i] != temp.elements[i]) return true;
    }
    return false;
}

//Скалярные операции
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType& temp) const
{
    TVector<ValueType> out(size, startIndex);
    for (unsigned i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] + temp;
    }
    return out;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType& temp) const
{
    TVector<ValueType> out(size, startIndex);
    for (unsigned i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] - temp;
    }
    return out;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType& temp) const
{
    TVector<ValueType> out(size, startIndex);
    for (unsigned i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] * temp;
    }
    return out;
}

//Векторные операции
template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector& temp) const
{
    if (size != temp.size) throw TException(BadSize);
    TVector<ValueType> out(size, startIndex);
    for (unsigned i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] + temp.elements[i];
    }
    return out;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector& temp) const
{
    if (size != temp.size) throw TException(BadSize);
    TVector<ValueType> out(size, startIndex);
    for (unsigned i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] - temp.elements[i];
    }
    return out;
}

template <typename ValueType>
ValueType TVector<ValueType>::operator*(const TVector& temp) const
{
    if ((size + startIndex) != (temp.size + temp.startIndex)) throw TException(BadSize);
    ValueType out;
    out = 0;
    for (unsigned i = 0; i < (size + startIndex); i++)
    {
        out += (*this)[i] * temp[i];
    }
    return out;
}

//Операция присваивания
template <typename ValueType>
TVector<ValueType>& TVector<ValueType>::operator=(const TVector& temp)
{
    if (elements == temp.elements) return *this;
    if (size != temp.size)
    {
        delete[] elements;
        size = temp.size;
        startIndex = temp.startIndex;
        elements = new ValueType[size];
    }
    startIndex = temp.startIndex;
    for (unsigned i = 0; i < size; i++)
    {
        elements[i] = temp.elements[i];
    }
    return *this;
}

//Получение длинны(не размера) вектора
template <typename ValueType>
ValueType TVector<ValueType>::Length() const
{
    ValueType out = 0;
    for (unsigned i = 0; i < size; i++)
    {
        out += elements[i] * elements[i];
    }
    return sqrt(out);
}

//Операции ввода-вывода в поток
template <typename ValueType>
std::ostream& operator<<(std::ostream& out, const TVector<ValueType>& vector)
{
    for (unsigned i = 0; i < (vector.size + vector.startIndex); i++)
    {
        out << vector[i] << ' ';
    }
    return out;
}

template <typename ValueType>
std::istream& operator>>(std::istream& in, TVector<ValueType>& vector)
{
    for (unsigned i = 0; i < vector.size; i++)
    {
        in >> vector.elements[i];
    }
    return in;
}

//Операции индексации
template <typename ValueType>
ValueType& TVector<ValueType>::operator[](unsigned index)
{
    if (index < startIndex) throw TException(WriteOnReadOnly);
    index -= startIndex;
    if (index >= size) throw TException(BadIndex);
    return elements[index];
}

template <typename ValueType>
const ValueType TVector<ValueType>::operator[](unsigned index) const
{
    if (index < startIndex) return 0;
    index -= startIndex;
    if (index >= size) throw TException(BadIndex);
    return elements[index];
}
