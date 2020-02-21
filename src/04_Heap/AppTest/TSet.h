#pragma once

class TSet
{
    size_t size;
    int* array;

public:
    TSet(size_t size_ = 10);
    TSet(size_t size_, int* array_);
    ~TSet();

    void createSubset(int id);
    void uniteSubsets(int a, int b);
    int getSubsetName(int id);
   
};