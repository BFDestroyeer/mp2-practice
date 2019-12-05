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
	pNext = nullptr;
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

std::ostream& operator<<(std::ostream& out, const TNode<int, double>& node)
{
	if (*(node.pData) > 0)
		out << "+";
	else
		out << "-";
	if ((*(node.pData) != 1 && *(node.pData) != -1) || node.key == 0)
		out << abs(*(node.pData));
	if (node.key / 100 != 0)
		out << "x^" << (node.key / 100);
	if (node.key % 100 / 10 != 0)
		out << "y^" << (node.key % 100 / 10);
	if (node.key % 10 != 0)
		out << "z^" << (node.key % 10);
	return out;
}
