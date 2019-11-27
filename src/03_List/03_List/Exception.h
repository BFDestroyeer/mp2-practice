#pragma once

enum TException_Type
{
	NotInSystem,
	UnexpectedChar
};

struct TException
{
    TException_Type type;

    TException(TException_Type type_)
    {
        type = type_;
    }
};