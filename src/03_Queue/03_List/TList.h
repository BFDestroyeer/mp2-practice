#pragma once

#include "TNode.h"

template <typename TKey, typename TData>
class TList
{
public:
	
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
	TNode<TKey, TData>* pCurrent;

public:
	TList();
	TList(const TList<TKey, TData>& temp);
	TList(const TNode<TKey, TData>* node_);
	~TList();

	void InstertForward(TKey key_, TData* pData_);
	void InstertBackward(TKey key_, TData* pData_);
	void InstertBefore(TKey key_a, TKey key_, TData* pData_);
	void InstertAfter(TKey key_b ,TKey key_, TData* pData_);
	
	void Remove(TKey key_);

	void Reset();
	bool IsEnded() const;
	void Next();
};

template <typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pFirst = new TNode<TKey, TData>();
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = pFirst;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TList& temp)
{
	pFirst = new TNode<TKey, TData>(*(temp.pFirst));
	TNode<TKey, TData>* node_ = pFirst, node_temp = temp.pFirst;
	while (node_temp->pNext != nullptr)
	{
		node_->pNext = new TNode<TKey, TData>(*(node_temp->pNext));
		node_ = node_->pNext;
		node_temp = node_temp->pNext;
	}
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = pFirst;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TNode<TKey, TData > * node_)
{
	
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
void TList<TKey, TData>::InstertForward(TKey key_, TData* pData_)
{
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	temp->pNext = pFirst;
	if (pCurrent == pFirst) pPrevious = temp;
	pFirst = temp;
}