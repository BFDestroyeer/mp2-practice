#pragma once

#include "TNode.h"

template <typename TKey, typename TData>
class TList
{
protected:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
	TNode<TKey, TData>* pCurrent;

public:
	TList();
	TList(const TList<TKey, TData>& temp);
	TList(const TNode<TKey, TData>* node_);
	~TList();

	TData GetCurrentData() const;
	TKey GetCurrentKey() const;

	void InsertForward(TKey key_, TData* pData_);
	void InsertBackward(TKey key_, TData* pData_);
	void InsertBefore(TKey key_b, TKey key_, TData* pData_);
	void InsertAfter(TKey key_a ,TKey key_, TData* pData_);
	
	void Remove(TKey key_);

	void Reset();
	bool IsEnded() const;
	bool IsEmpty() const;
	void Next();

	template <typename TKey, typename TData>
	friend std::ostream& operator<<(std::ostream& out, const TList<TKey, TData>& list);
};

template <typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pFirst = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = nullptr;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TList& temp)
{
	pFirst = new TNode<TKey, TData>(*(temp.pFirst));
	TNode<TKey, TData> *node_ = pFirst, *node_temp = temp.pFirst;
	while (node_temp->pNext != nullptr)
	{
		node_->pNext = new TNode<TKey, TData>(*(node_temp->pNext));
		node_ = node_->pNext;
		node_temp = node_temp->pNext;
	}
	pPrevious = nullptr;
	if (pFirst != nullptr) pNext = pFirst->pNext;
	pCurrent = pFirst;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TNode<TKey, TData >* node_)
{
	pFirst = new TNode<TKey, TData>(*node_);
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = pFirst;
}

template <typename TKey, typename TData>
TList<TKey, TData>::~TList()
{
	TNode<TKey, TData> *del = pFirst, *next;
	while (del != nullptr)
	{
		next = del->pNext;
		delete del;
		del = next;
		
	}
}

template <typename TKey, typename TData>
TData TList<TKey, TData>::GetCurrentData() const
{
	if (pCurrent == nullptr) throw "Cant";
	return *(pCurrent->pData);
}

template <typename TKey, typename TData>
TKey TList<TKey, TData>::GetCurrentKey() const
{
	if (pCurrent == nullptr) throw "Cant";
	return pCurrent->key;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertForward(TKey key_, TData* pData_)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TKey, TData>(key_, pData_);
		pCurrent = pFirst;
		return;
	}
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	temp->pNext = pFirst;
	if (pCurrent == pFirst) pPrevious = temp;
	pFirst = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBackward(TKey key_, TData* pData_)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TKey, TData>(key_, pData_);
		pCurrent = pFirst;
		return;
	}
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	TNode<TKey, TData>* node = pFirst;
	while (node->pNext != nullptr)
	{
		node = node->pNext;
	}
	node->pNext = temp;
	if (pCurrent = node) pNext = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey key_b, TKey key_, TData* pData_)
{
	if (pFirst == nullptr) return;
	if (pFirst->key == key_b)
	{
		InsertForward(key_, pData_);
		return;
	}
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node->pNext != nullptr) && (prev_node->pNext->key != key_b))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node->pNext == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext;
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	prev_node->pNext = temp;
	temp->pNext = next_node;
	if (pCurrent == prev_node) pNext = temp;
	if (pCurrent == next_node) pPrevious = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey key_a, TKey key_, TData* pData_)
{
	if (pFirst == nullptr) return;
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node != nullptr) && (prev_node->key != key_a))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext;
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	prev_node->pNext = temp;
	temp->pNext = next_node;
	if (pCurrent == prev_node) pNext = temp;
	if (pCurrent == next_node) pPrevious = temp;

}

template <typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey key_)
{
	if (pFirst == nullptr) return;
	if (pFirst->key == key_)
	{
		TNode<TKey, TData>* next_node = pFirst->pNext;
		if (pCurrent == pFirst) pCurrent = nullptr;
		if (pPrevious == pFirst) pPrevious = nullptr;
		if (pNext == pFirst) pNext = pNext->pNext;
		delete pFirst;
		pFirst = next_node;
		return;
	}
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node->pNext != nullptr) && (prev_node->pNext->key != key_))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node->pNext == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext->pNext;
	if (pCurrent == prev_node->pNext) pCurrent = nullptr;
	if (pNext == prev_node->pNext) pNext = prev_node->pNext->pNext;
	if (pPrevious == prev_node) pPrevious = prev_node;
	delete prev_node->pNext;
	prev_node->pNext = next_node;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	pCurrent = pFirst;
	pPrevious = nullptr;
	if (pFirst != nullptr) pNext = pFirst->pNext;
}

template <typename TKey, typename TData>
bool TList<TKey, TData>::IsEnded() const
{
	if (pCurrent == nullptr) return true;
	return false;
}

template <typename TKey, typename TData>
bool TList<TKey, TData>::IsEmpty() const
{
	if ((pCurrent == nullptr) && (pNext == nullptr)) return true;
	return false;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded() == true) throw "It's END";
	if (pCurrent != nullptr)
	{
		pPrevious = pCurrent;
		pCurrent = pNext;
	}
	else
	{
		pCurrent = pNext;
	}
	if (pNext != nullptr)
	{
		pNext = pNext->pNext;
	}
	else
	{
		pNext = nullptr;
	}
}

template <typename TKey, typename TData>
std::ostream& operator<<(std::ostream& out, const TList<TKey, TData>& list)
{
	TNode<TKey, TData> *node = list.pFirst;
	while (node != nullptr)
	{
		out << *(node) << std::endl;
		node = node->pNext;
	}
	return out;
}