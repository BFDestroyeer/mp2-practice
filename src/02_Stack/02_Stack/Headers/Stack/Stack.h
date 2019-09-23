#pragma once
#include <iostream>

template<typename ValueType>
class Stack
{
protected:
    unsigned size;
    unsigned head;
    ValueType* elements;

public:
    Stack(unsigned size_ = 10);
    Stack(const Stack& temp);
    ~Stack();

    void Push(ValueType element);   //Вставить элемент
    ValueType Top();                //Вернуть первый элемент
    ValueType Pop();                //Вынуть первый элемент

    bool IsEmpty();
    bool IsFull();
};

template<typename ValueType>
Stack<ValueType>::Stack(unsigned size_)
{
    size = size_;
    head = 0;
    elements = new ValueType[size_];
}

template<typename ValueType>
Stack<ValueType>::Stack(const Stack& temp)
{
    size = temp.size;
    head = temp.head;
    delete[] elements;
    if (size != 0)
    {
        elements = new ValueType[size];
        std::memcpy(elements, temp.elements, size * sizeof(ValueType));
    }
    else
    {
        elements = 0;
    }
}

template<typename ValueType>
Stack<ValueType>::~Stack()
{
    delete[] elements;
}

template<typename ValueType>
void Stack<ValueType>::Push(ValueType element)
{
    if (IsFull()) throw "Full";
    elements[head++] = element;
}

template<typename ValueType>
ValueType Stack<ValueType>::Top()
{
    if (IsEmpty()) throw "Empty";
    return elements[head-1];
}

template<typename ValueType>
ValueType Stack<ValueType>::Pop()
{
    if (IsEmpty()) throw "Empty";
    return elements[--head];
}

template<typename ValueType>
bool Stack<ValueType>::IsEmpty()
{
    if (head == 0) return true;
    return false;
}

template<typename ValueType>
bool Stack<ValueType>::IsFull()
{
    if (head == size) return true;
    return false;
}