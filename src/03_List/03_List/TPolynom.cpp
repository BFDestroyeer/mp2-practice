#include "TPolynom.h"

TPolynom::TPolynom()
{
	list = new TList<int, float>;
}

TPolynom::TPolynom(const TPolynom& temp)
{
	list = new TList<int, float>(*(temp.list));
}

TPolynom::~TPolynom()
{
	delete list;
}

TPolynom& TPolynom::operator=(const TPolynom& temp)
{
	delete list;
	list = new TList<int, float>(*(temp.list));
}

TPolynom TPolynom::operator+(const TPolynom& temp)
{
	TList<int, float>* out = new TList<int, float>(*list);
	//TODO: make
}

TPolynom TPolynom::operator+(const TNode<int, float>& node)
{
	return *this;
}