#pragma once

#include <string>

enum TExceptionCode
{
    BadId,
    BadEdge,
    ContainterIsFull
};

struct TException
{
    TExceptionCode code;
    size_t line;
    std::string messange;

    TException(TExceptionCode code_, size_t line_);
};
