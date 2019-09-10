#pragma once
#include <iostream>

template <typename ValueType>
class TVector
{
protected:
    unsigned size;          //Размер вектора
    ValueType* elements;    //Данные
    unsigned startIndex;    //Начальный индекс 

public:
    TVector(unsigned size_ = 10, unsigned startIndex_ = 0);
    TVector(const TVector& temp);
    ~TVector();

    //Чтение полей
    unsigned GetSize();
    unsigned GetStartIndex();

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
};


template <typename ValueType>
TVector<ValueType>::TVector(unsigned size_, unsigned startIndex_)
{
    size = size_;
    startIndex = startIndex_;
    elements = new ValueType[size];
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
    delete[] elements;
}

//Чтение полей
template <typename ValueType>
unsigned TVector<ValueType>::GetSize()
{
    return size;
}

template <typename ValueType>
unsigned TVector<ValueType>::GetStartIndex()
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
    if (size != temp.size) throw "Wrong range";
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
    if (size != temp.size) throw "Wrong range";
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
    if (size != temp.size) throw "Wrong range";
    ValueType out = 0;
    for (unsigned i = 0; i < size; i++)
    {
        out += elements[i] * temp.elements[i];
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
    for (unsigned i = 0; i < vector.size; i++)
    {
        out << vector.elements[i] << ' ';
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
    index += startIndex;
    if ((index < 0) || (index >= size)) throw "Bad index";
    return elements[index];
}
