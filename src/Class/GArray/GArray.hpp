#ifndef __GENERIC_ARRAY_HPP__
#define __GENERIC_ARRAY_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template <class T>
class GArray
{
private:
    std::vector<T> buffer;

public:
    GArray();
    ~GArray();

    int getLength();
    T &getElmt(int);
    int getIdxMax();

    void push(T);
    void gSort();
};

#endif