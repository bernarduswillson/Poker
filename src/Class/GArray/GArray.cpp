#include "GArray.hpp"

template <typename T>
GArray<T>::GArray() {}

template <typename T>
GArray<T>::~GArray() {}

template <typename T>
int GArray<T>::getLength()
{
    return this->buffer.size();
}

template <typename T>
T &GArray<T>::getElmt(int idx)
{
    return this->buffer[idx];
}

template <typename T>
int GArray<T>::getIdxMax()
{
    int maxIdx = 0;
    for (int i = 1; i < this->buffer.size(); i++)
    {
        if (this->buffer[i] >= this->buffer[maxIdx])
        {
            maxIdx = i;
        }
    }
    return maxIdx;
}

template <typename T>
void GArray<T>::push(T elmt)
{
    this->buffer.push_back(elmt);
}