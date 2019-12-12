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
};

TMonom::TMonom(unsigned key_, const double* pData_) : TNode<unsigned, double>(key_, pData)
{
	if (key > 999) throw TException(NotInSystem);
}

TMonom::TMonom(unsigned key_, const double& data) : TNode<unsigned, double>(key_, pData)
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
