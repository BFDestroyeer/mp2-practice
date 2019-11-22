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
	TPolynom operator*(const TPolynom& temp);

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
	return out;
}

TPolynom TPolynom::operator+(const TNode<int, double>& node)
{
	TPolynom out(*this);
	out.list->Reset();
	while (!out.list->IsEnded())
	{
		if (out.list->GetCurrentKey() == node.key)
		{
			*(out.list->pCurrent) = *(out.list->pCurrent) + node;
			return out;
		}
		if (out.list->GetCurrentKey() < node.key)
		{
			out.list->InsertBefore(out.list->GetCurrentKey(), node.key, node.pData);
			return out;
		}
		out.list->Next();
	}
	out.list->InsertBackward(node.key, node.pData);
	return out;
}

std::ostream& operator<<(std::ostream& out, const TPolynom& polynom)
{
	out << *(polynom.list);
	return out;
}