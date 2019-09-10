#pragma once
#include "..//TVector.h"

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
    TMatrix(unsigned size_ = 10);
    TMatrix(const TMatrix& temp);
    TMatrix(const TVector<TVector<ValueType> > temp);
    ~TMatrix();

    //Чтение полей
    unsigned GetSize();

    //Операции сравнения
    bool operator==(const TMatrix& temp) const;
    bool operator!=(const TMatrix& temp) const;

    //Скалярные операции
    TMatrix operator+(const ValueType& temp) const;
    TMatrix operator-(const ValueType& temp) const;
    TMatrix operator*(const ValueType& temp) const;

    //Матричные операции
    TMatrix operator+(const TMatrix& temp) const;
    TMatrix operator-(const TMatrix& temp) const;
    TMatrix operator*(const TMatrix& temp) const;

    //Операция умножения на вектор
    TVector<ValueType> operator*(const TVector<ValueType>& temp) const;

    //Операции ввода-вывода в поток
    friend std::ostream& operator<<(std::ostream& out, const TMatrix& matrix);
    friend std::istream& operator>>(std::istream& in, TMatrix& vector);
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(unsigned size_)
{
    /*size = size_;
    for (int i = 0; i < size; i++)
    {
        
    }*/
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix& temp)
{
    if (this->size != temp.size)
    {
        delete[] this->elements;
        this->elements = new TVector<ValueType>(temp.size)[temp.size];
    }
    for (int i = 0; i < this->size; i++)
    {
        this->elements[i] = temp.elements[i];
    }
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> > temp)
{
    if (this->size != temp.size)
    {
        delete[] this->elements;
        this->elements = new TVector<ValueType>(temp.size)[temp.size];
    }
    for (int i = 0; i < this->size; i++)
    {
        this->elements[i] = temp.elements[i];
    }
}

//Чтение полей
template <typename ValueType>
unsigned TMatrix<ValueType>::GetSize()
{
    return this->size;
}

//Операции сравнения
template <typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix& temp) const
{
    if (this->elements == temp.elements) return true;
    if (this->size != temp.size) return false;
    for (int i = 0; i < this->size; i++)
    {
        if (this->elements[i] != temp.elements[i]) return false;
    }
    return true;
}

template <typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix& temp) const
{
    if (this->elements == temp.elements) return false;
    if (this->size != temp.size) return true;
    for (int i = 0; i < this->size; i++)
    {
        if (this->elements[i] != temp.elements[i]) return true;
    }
    return false;
}

//Скалярные операции
template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType& temp) const
{
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] + temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const ValueType& temp) const
{
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] - temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const ValueType& temp) const
{
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] * temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix& temp) const
{
    if (this->size != temp.size) throw "Wrong range";
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] + temp.elements[i];
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType>TMatrix<ValueType>::operator-(const TMatrix& temp) const
{
    if (this->size != temp.size) throw "Wrong range";
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] - temp.elements[i];
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& temp) const
{

}

//Операция умножения на вектор
template <typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& temp) const
{
    if (this->size != temp.size) throw "Wrong range";
    TVector<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = 0; j < this->size; j++)
        {
            out[i] += this->elements[j][i] * temp.elements[j];
        }
    }
    return out;
}

//Операции ввода-вывода в поток
template <typename ValueType>
std::ostream& operator<<(std::ostream& out, const TMatrix<ValueType>& matrix)
{
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = 0; j < this->size; j++)
        {
            out << this->elements[j][i] << ' ';
        }
        out << std::endl;
    }
    return out;
}

template <typename ValueType>
std::istream& operator>>(std::istream& in, TMatrix<ValueType>& vector)
{
    //Чтение size?
    for (unsigned i = 0; i < (this->size * this->size); i++)
    {
        for (unsigned j = 0; j < (this->size * this->size); j++)
        in >> this->elements[j][i];
    }
    return in;
}