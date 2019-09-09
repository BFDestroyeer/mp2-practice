#include "..//TVector.h"

template <typename ValueType>
class TMatrix : TVector<TVector<ValueType> >
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
    TVector operator*(const TVector& temp) const;

    //Операции ввода-вывода в поток
    friend std::ostream& operator<<(ostream& out, const TMatrix& matrix);
    friend std::istream& operator>>(istream& in, const TMatrix& matrix);
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
    if (size != temp.size)
    {
        delete[] elements;
        elements = new TVector<ValueType>(temp.size)[temp.size];
    }
    for (int i = 0; i < size; i++)
    {
        elements[i] = temp.elements[i];
    }
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> > temp)
{
    if (size != temp.size)
    {
        delete[] elements;
        elements = new TVector<ValueType>(temp.size)[temp.size];
    }
    for (int i = 0; i < size; i++)
    {
        elements[i] = temp.elements[i];
    }
}

//Чтение полей
template <typename ValueType>
unsigned TMatrix<ValueType>::GetSize()
{
    return size;
}

//Операции сравнения
template <typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix& temp) const
{
    if (elements == temp.elements) return true;
    if (size != temp.size) return false;
    for (int i = 0; i < size; i++)
    {
        if (elements[i] != temp.elements[i]) return false;
    }
    retrun true;
}

template <typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix& temp) const
{
    if (elements == temp.elements) return false;
    if (size != temp.size) return true;
    for (int i = 0; i < size; i++)
    {
        if (elements[i] != temp.elements[i]) return true;
    }
    retrun false;
}

//Скалярные операции
template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType& temp) const
{
    TMatrix<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] + temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const ValueType& temp) const
{
    TMatrix<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] - temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const ValueType& temp) const
{
    TMatrix<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] * temp;
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix& temp) const
{
    if (size != temp.size) throw "Wrong range";
    TMatrix<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] + temp.elements[i];
    }
    return out;
}

template <typename ValueType>
TMatrix<ValueType>TMatrix<ValueType>::operator-(const TMatrix& temp) const
{
    if (size != temp.size) throw "Wrong range";
    TMatrix<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        out.elements[i] = elements[i] - temp.elements[i];
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
    if (size != temp.size) throw "Wrong range";
    TVector<ValueType> out(size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            out[i] += elements[j][i] * temp.elements[j];
        }
    }
    return out;
}

//Операции ввода-вывода в поток
template <typename ValueType>
std::ostream& operator<<(std::ostream& out, const TMatrix<ValueType>& matrix)
{
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            out << elements[j][i] << ' ';
        }
        out << std::endl;
    }
}

template <typename ValueType>
std::istream& operator>>(std::istream& in, const TMatrix<ValueType>& matrix)
{
    //Чтение size?
    for (i = 0; i < (size * size); i++)
    {
        in << elements[j][i];
    }
}