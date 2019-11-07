#pragma once

#include "Stack.h"
#include "Exception.h"

template<typename ValueType>
class ArrayStack : public Stack<ValueType>
{
protected:
    size_t size;
    size_t head;
    ValueType* elements;

public:
    ArrayStack(size_t size = 10);
    ArrayStack(const ArrayStack& temp);
    ~ArrayStack();

    void Push(ValueType element);   //Вставить элемент
    ValueType Top() const;          //Вернуть первый элемент
    void Pop();						//Вынуть первый элемент

    bool IsEmpty() const;
    bool IsFull() const;
};

template<typename ValueType>
ArrayStack<ValueType>::ArrayStack(size_t size_)
{
    if (size_ == 0) throw Exception(CantCreate);
    size = size_;
    head = 0;
    elements = new ValueType[size];
}

template<typename ValueType>
ArrayStack<ValueType>::ArrayStack(const ArrayStack<ValueType>& temp)
{
    size = temp.size;
    head = temp.head;
    elements = new ValueType[size];
    for (unsigned i = 0; i < head; i++)
    {
        elements[i] = temp.elements[i];
    }
}

template<typename ValueType>
ArrayStack<ValueType>::~ArrayStack()
{
    delete[] elements;
}

template<typename ValueType>
void ArrayStack<ValueType>::Push(ValueType element)
{
    if (IsFull()) throw Exception(Empty);
    elements[head++] = element;
}

template<typename ValueType>
ValueType ArrayStack<ValueType>::Top() const
{
    if (IsEmpty()) throw Exception(Empty);
    return elements[head-1];
}

template<typename ValueType>
void ArrayStack<ValueType>::Pop()
{
    if (IsEmpty()) throw Exception(Empty);
	head--;
}

template<typename ValueType>
bool ArrayStack<ValueType>::IsEmpty() const
{
    if (head == 0) return true;
    return false;
}

template<typename ValueType>
bool ArrayStack<ValueType>::IsFull() const
{
    if (head == size) return true;
    return false;
}