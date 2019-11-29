#pragma once

enum TException_Type
{
	NotInSystem,
	UnexpectedChar,
	CantReturnEmpty,
	CantFind,
	ListIsEnded
};

struct TException
{
    TException_Type type;

    TException(TException_Type type_)
    {
        type = type_;
    }
};