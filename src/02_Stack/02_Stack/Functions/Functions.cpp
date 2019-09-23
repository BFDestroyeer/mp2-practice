#include "Functions.h"

const unsigned Functions::Priority(const char opr)
{
    if ((opr == '*') || (opr == '/')) return 3;
    if ((opr == '+') || (opr == '-')) return 2;
    if (opr == ')') return 1;
    return 0;
}