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
	TPolynom out;
	TNode<int, double>* first = list->pFirst;
	TNode<int, double>* second = temp.list->pFirst;
	while (first != nullptr || second != nullptr)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(second->key, second->pData);
			second = second->pNext;
		}
		else if (second == nullptr)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key > second->key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key < second->key)
		{
			out.list->InsertBackward(second->key, second->pData);
			second = second->pNext;
		}
		else
		{
			if (*(first->pData) != -*(second->pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) + *(second->pData));
			}
			first = first->pNext;
			second = second->pNext;
		}
	}
	return out;
}

TPolynom TPolynom::operator+(const TNode<int, double>& node)
{
	TPolynom out;
	TNode<int, double>* first = list->pFirst;
	bool isInserted = false;
	while (first != nullptr || !isInserted)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (first->key > node.key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (!isInserted && first->key < node.key)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (!isInserted)
		{
			if (*(first->pData) != -*(node.pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) + *(node.pData));
			}
			first = first->pNext;
			isInserted = true;
		}
		else
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
	}
	return out;
}

TPolynom TPolynom::operator-(const TPolynom& temp)
{
	TPolynom out;
	TNode<int, double>* first = list->pFirst;
	TNode<int, double>* second = temp.list->pFirst;
	while (first != nullptr || second != nullptr)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(-second->key, second->pData);
			second = second->pNext;
		}
		else if (second == nullptr)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key > second->key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (first->key < second->key)
		{
			out.list->InsertBackward(-second->key, second->pData);
			second = second->pNext;
		}
		else
		{
			if (*(first->pData) != *(second->pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) - *(second->pData));
			}
			first = first->pNext;
			second = second->pNext;
		}
	}
	return out;
}

TPolynom TPolynom::operator-(const TNode<int, double>& node)
{
	TPolynom out;
	TNode<int, double>* first = list->pFirst;
	bool isInserted = false;
	while (first != nullptr || !isInserted)
	{
		if (first == nullptr)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (first->key > node.key)
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
		else if (!isInserted && first->key < node.key)
		{
			out.list->InsertBackward(node.key, node.pData);
			isInserted = true;
		}
		else if (!isInserted)
		{
			if (*(first->pData) != *(node.pData))
			{
				out.list->InsertBackward(first->key, *(first->pData) - *(node.pData));
			}
			first = first->pNext;
			isInserted = true;
		}
		else
		{
			out.list->InsertBackward(first->key, first->pData);
			first = first->pNext;
		}
	}
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