#pragma once

//template <typename Type>
class THeap
{
    size_t max_size;
    size_t size;
    size_t d;
    int* array;
    
public:
    THeap(unsigned d_, size_t max_size_);
    ~THeap();

    void Transpose(size_t a, size_t b);
    void moveUp(size_t id);
    void moveDown(size_t id);

    int getMinKey();
    int getMinChild(size_t id);

private:
    void Heaping();
};