#include <time.h>
#include <random>

#include "Generate.h"

namespace Generate
{
    TVector<TVector<double>> VectorOfVectors(const unsigned size_)
    {
        TVector<TVector<double>> out(size_);
        for (unsigned i = 0; i < size_; i++)
        {
            out[i] = TVector<double>(size_ - i, i);
        }
        srand(time(0));
        for (unsigned i = 0; i < size_; i++)
        {
            for (unsigned j = i; j < size_; j++)
            {
                out[i][j] = rand() % 10;
            }
        }
        return out;
    }
}