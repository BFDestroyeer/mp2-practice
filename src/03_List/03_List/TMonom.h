#pragma once

#include "TNode.h"
#include "TException.h"

class TMonom : public TNode<unsigned, double>
{
public:
	TMonom(unsigned key_, const double* pData_);
	TMonom(unsigned key_, const double& data);
	TMonom(const TMonom& temp);
	TMonom(const TNode<unsigned, double>& temp);
	~TMonom();

	TNode<unsigned, double> operator*(const TMonom& temp);
};

TMonom::TMonom(unsigned key_, const double* pData_) : TNode<unsigned, double>(key_, pData_)
{
	if (key > 999) throw TException(NotInSystem);
}

TMonom::TMonom(unsigned key_, const double& data) : TNode<unsigned, double>(key_, data)
{
	if (key > 999) throw TException(NotInSystem);
}


TMonom::TMonom(const TMonom& temp) : TNode<unsigned, double>(temp)
{

}

TMonom::TMonom(const TNode<unsigned, double>& temp) : TNode<unsigned, double>(temp)
{

}

TMonom::~TMonom()
{

}

TNode<unsigned, double> TMonom::operator*(const TMonom& temp)
{
	if ((key / 100 + temp.key / 100) >= 10) throw TException(NotInSystem);
	if ((key % 100 / 10 + temp.key % 100 / 10) >= 10) throw TException(NotInSystem);
	if ((key % 10 + temp.key % 10) >= 10) throw TException(NotInSystem);
	TNode<unsigned, double> out(key + temp.key, *pData * *(temp.pData));
	return out;
}