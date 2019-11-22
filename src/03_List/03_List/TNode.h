#pragma once

#include <iostream>

template <typename TKey, typename TData>
struct TNode
{
	TKey key;
	TData* pData;
	TNode* pNext;

	TNode();
	TNode(TKey key_, const TData* pData_);
	TNode(TKey key_, const TData& data);
	TNode(const TNode<TKey, TData>& temp);
	~TNode();

	TNode<TKey, TData>& operator=(const TNode<TKey, TData>& temp);

	template <typename TKey, typename TData>
	friend std::ostream& operator<<(std::ostream& out, const TNode<TKey, TData>& node);
};

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	key = NULL;
	pData = new TData;
	pNext = nullptr;
}

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey key_, const TData* pData_)
{
	key = key_;
	pData = new TData;
	*pData = *pData_;
	pNext = nullptr;
}

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey key_, const TData& data_)
{
	key = key_;
	pData = new TData;
	*pData = data_;
	pNext = nullptr;
}

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& temp)
{
	key = temp.key;
	pData = new TData;
	*pData = *(temp.pData);
	pNext = temp.pNext;
}

template <typename TKey, typename TData>
TNode<TKey, TData>::~TNode()
{
	delete pData;
}

template <typename TKey, typename TData>
TNode<TKey, TData>& TNode<TKey, TData>::operator=(const TNode<TKey, TData>& temp)
{
	if (this == &temp)
	{
		return *this;
	}
	key = temp.key;
	*pData = *(temp.pData);
	return *this;
}

template <typename TKey, typename TData>
std::ostream& operator<<(std::ostream& out, const TNode<TKey, TData>& node)
{
	out << "Key: " << node.key << " Data: " << *(node.pData);
	return out;
}

//Monom's operators
TNode<int, double> operator+(TNode<int, double>& a, const TNode<int, double>& b)
{
	if (a.key != b.key) throw "Output is not monom";
	TNode<int, double> out;
	out.key = a.key;
	*(out.pData) = *(a.pData) + *(b.pData);
	out.pNext = nullptr;
	return out;
}

TNode<int, double> operator-(TNode<int, double>& a, const TNode<int, double>& b)
{
	if (a.key != b.key) throw "Output is not monom";
	TNode<int, double> out;
	out.key = b.key;
	*(out.pData) = *(a.pData) - *(b.pData);
	out.pNext = nullptr;
	return out;
}

TNode<int, double> operator*(TNode<int, double>& a, const TNode<int, double>& b)
{
	TNode<int, double> out;
	if ((a.key / 100 + b.key / 100) >= 10) throw "Not in system";
	if ((a.key % 100 / 10 + b.key % 100 / 10) >= 10) throw "Not in system";
	if ((a.key % 10 + b.key % 10) >= 10) throw "Not in system";
	out.key = a.key + b.key;
	*(out.pData) = *(a.pData) * *(b.pData);
	out.pNext = nullptr;
	return out;
}

std::ostream& operator<<(std::ostream& out, const TNode<int, double>& node)
{
	out << *(node.pData);
	if (node.key / 100 != 0)
		out << "x^" << (node.key / 100);
	if (node.key % 100 / 10 != 0)
		out << "y^" << (node.key % 100 / 10);
	if (node.key % 10 != 0)
		out << "z^" << (node.key % 10);
	return out;
}
