#include "..//TVector.h"

template <typename ValueType>
class TMatrix : TVector<TVector<ValueType> >
{
public:
    TMatrix(unsigned size_ = 10);
    TMatrix(const TMatrix& temp);
    TMatrix(conts TVector<TVector<ValType> >);
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
    TMatrix operator+(const TMatrix& temp) const;
    TMatrix operator*(const TMatrix& temp) const;

    //Операция умножения на вектор
    TVector operator*(const TVector& temp) const;

    //Операции ввода-вывода в поток
    friend std::ostream& operator<<(ostream& out, const TMatrix vector);
    friend std::istream& operator>>(istream& in, const TMatrix& vector);
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(unsigned size_)
{
    size = size_;
    for (int i = 0; i < size; i++)
    {
        
    }
}