#pragma once

template<typename ValueType>
class Stack
{
public:
	virtual void Push(ValueType element) = 0;
	virtual ValueType Top() const = 0;
	virtual void Pop() = 0;

	virtual bool IsEmpty()const = 0;
	virtual bool IsFull() const = 0;
};