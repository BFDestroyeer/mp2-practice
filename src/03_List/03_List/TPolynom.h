#pragma once

#include "TList.h"

class TPolynom
{
public:
	TList<int, double>* list;

public:
	TPolynom();
	TPolynom(const TPolynom& temp);
	~TPolynom();

	TPolynom& operator=(const TPolynom& temp);
	TPolynom operator+(const TPolynom& temp);
	TPolynom operator+(const TNode<int, double>& node);
	TPolynom operator-(const TPolynom& temp);
	TPolynom operator-(const TNode<int, double>& node);
	TPolynom operator*(const TPolynom& temp);
	TPolynom operator*(const TNode<int, double>& node);

	friend std::ostream& operator<<(std::ostream& out, const TPolynom& polynom);
};

TPolynom::TPolynom()
{
	list = new TList<int, double>;
}

TPolynom::TPolynom(const TPolynom& temp)
{
	list = new TList<int, double>(*(temp.list));
}

TPolynom::~TPolynom()
{
	delete list;
}

TPolynom& TPolynom::operator=(const TPolynom& temp)
{
	delete list;
	list = new TList<int, double>(*(temp.list));
	return *this;
}

TPolynom TPolynom::operator+(const TPolynom& temp)
{
	TPolynom out(*this);
	TNode<int, double>* iter = temp.list->pFirst;
	while (iter != nullptr)
	{
		out = out + *iter;
		iter = iter->pNext;
	}
	return out;
}

TPolynom TPolynom::operator+(const TNode<int, double>& node)
{
	TPolynom out(*this);
	TNode<int, double>* iter = out.list->pFirst;
	while (iter != nullptr)
	{
		if (iter->key == node.key)
		{
			*iter = *iter + node;
			return out;
		}
		if (iter->key < node.key)
		{
			out.list->InsertBefore(iter->key, node.key, node.pData);
			return out;
		}
		iter = iter->pNext;
	}
	out.list->InsertBackward(node.key, node.pData);
	return out;
}

TPolynom TPolynom::operator-(const TPolynom& temp)
{
	TPolynom out(*this);
	TNode<int, double>* iter = temp.list->pFirst;
	while (iter != nullptr)
	{
		out = out - *iter;
		iter = iter->pNext;
	}
	return out;
}

TPolynom TPolynom::operator-(const TNode<int, double>& node)
{
	TPolynom out(*this);
	TNode<int, double>* iter = out.list->pFirst;
	while (iter != nullptr)
	{
		if (iter->key == node.key)
		{
			*iter = *iter - node;
			return out;
		}
		if (iter->key < node.key)
		{
			out.list->InsertBefore(iter->key, node.key, -*node.pData);
			return out;
		}
		iter = iter->pNext;
	}
	out.list->InsertBackward(node.key, -*node.pData);
	return out;
}

TPolynom TPolynom::operator*(const TPolynom& temp)
{
	TPolynom out(*this);
	TNode<int, double>* iter = temp.list->pFirst;
	while (iter != nullptr)
	{
		out = out * *iter;
		iter = iter->pNext;
	}
	return out;
	return out;
}

TPolynom TPolynom::operator*(const TNode<int, double>& node)
{
	TPolynom out(*this);
	TNode<int, double>* iter = out.list->pFirst;
	while (iter != nullptr)
	{
		*iter = *iter * node;
		iter = iter->pNext;
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const TPolynom& polynom)
{
	out << *(polynom.list);
	return out;
}