#pragma once

#include <time.h>
#include <random>

#include "TGraph.h"
#include "TException.h"

static class Generator
{
public:
    static int* getRandomArray(size_t size, int max);
    static TGraph getRandomConnectedGraph(size_t size);
};

