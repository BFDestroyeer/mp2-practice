#pragma once

template <typename TKey, typename TData>
struct TNode
{
	TKey key;
	TData* pData;
	TNode* pNext;

	TNode();
	TNode(TKey key_, TData* pData_);
	TNode(const TNode<TKey, TData>& temp);
	~TNode();
};

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	pData = new TData;
	pNext = nullptr;
}

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey key_, TData* pData_)
{
	key = key_;
	pData = new TData;
	*pData = *pData_;
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