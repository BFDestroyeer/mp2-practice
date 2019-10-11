#pragma once
#include "TVector.h"

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
    explicit TMatrix(unsigned size_ = 10);
    TMatrix(const TMatrix& temp);
    TMatrix(const TVector<TVector<ValueType> > &temp);
    ~TMatrix();

    //Чтение полей
    unsigned GetSize() const;

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

    //Операция присваивания
    TMatrix& operator=(const TMatrix<ValueType>& temp);

    //Операции ввода-вывода в поток
    template <typename ValueType>
    friend std::ostream& operator<<(std::ostream& out, const TMatrix& matrix);
    template <typename ValueType>
    friend std::istream& operator>>(std::istream& in, TMatrix& matrix);

    //Алгебраические операции
    ValueType Determinant() const;
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(unsigned size_) : TVector<TVector<ValueType> >(size_)
{
    for (unsigned i = 0; i < this->size; i++)
    {
        this->elements[i] = TVector<ValueType>(this->size - i, i);
    }
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix& temp) : TVector<TVector<ValueType> >(temp)
{

}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> > &temp) : TVector<TVector<ValueType> >(temp)
{
}

template <typename ValueType>
TMatrix<ValueType>::~TMatrix()
{
    
}

//Чтение полей
template <typename ValueType>
unsigned TMatrix<ValueType>::GetSize() const
{
    return this->size;
}

//Операции сравнения
template <typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix& temp) const
{
    if (this->size != temp.size) return false;
    for (unsigned i = 0; i < this->size; i++)
    {
        if (this->elements[i] != temp.elements[i]) return false;
    }
    return true;
}

template <typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix& temp) const
{
    return (!(*this == temp));
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
    if (this->size != temp.size) throw TException(BadSize);
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
    if (this->size != temp.size) throw TException(BadSize);
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out.elements[i] = this->elements[i] - temp.elements[i];
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix<ValueType>& temp) const
{
    if (this->size != temp.size) throw TException(BadSize);
    TMatrix<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        for (unsigned j = i; j < this->size; j++)
        {
            out[i][j] = 0;
            for (unsigned k = i; k <= /*this->size - */j; k++)
            {
                    out[i][j] += (*this)[i][k] * temp[k][j];
            }
        }
    }
    return out;
}

//Операция умножения на вектор
template <typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& temp) const
{
    if (this->size != temp.GetSize()) throw TException(BadSize);
    TVector<ValueType> out(this->size);
    for (unsigned i = 0; i < this->size; i++)
    {
        out[i] = 0;
        for (unsigned j = i; j < this->size; j++)
        {
            out[i] += (*this)[i][j] * temp[j];
        }
    }
    return out;
}

//Операция присваивания
template <typename ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType>& temp)
{
    if (*this == temp) return *this;
    if (this->size != temp.size)
    {
        delete[] this->elements;
        this->size = temp.size;
        this->elements = new TVector<ValueType>[this->size];

    }
    this->size = temp.size;
    for (unsigned i = 0; i < this->size; i++)
    {
        this->elements[i] = temp.elements[i];
    }
    return *this;
}

//Операции ввода-вывода в поток
template <typename ValueType>
std::ostream& operator<<(std::ostream& out, const TMatrix<ValueType>& matrix)
{
    for (unsigned i = 0; i < matrix.GetSize(); i++)
    {
        out << matrix[i] << std::endl;
    }
    return out;
}

template <typename ValueType>
std::istream& operator>>(std::istream& in, TMatrix<ValueType>& matrix)
{
    for (unsigned i = 0; i <  matrix.GetSize(); i++)
    {
        
        in >> matrix[i];
    }
    return in;
}

//Алгебраические операции
template <typename ValueType>
ValueType TMatrix<ValueType>::Determinant() const
{
    if (this->size == 0) return 0;
    ValueType out = 1;
    for (unsigned i = 0; i < this->size; i++)
    {
        out *= (*this)[i][i];
    }
    return out;
}