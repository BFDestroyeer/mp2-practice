#include "TNode.h"

class TMonom : public TNode<unsigned, double>
{
public:
	TMonom();
	TMonom(unsigned key_, const double* pData_);
	TMonom(unsigned key_, const double& data);
	~TMonom();
};

TMonom::TMonom() : TNode<unsigned, double>()
{

}

TMonom::TMonom(unsigned key_, const double* pData_) : TNode<unsigned, double>(key_, pData)
{

}

TMonom::TMonom(unsigned key_, const double& data) : TNode<unsigned, double>(key_, pData)
{

}

TMonom::~TMonom()
{

}
