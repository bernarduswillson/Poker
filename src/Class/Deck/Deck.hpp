#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

#include "../InventoryHolder/InventoryHolder.hpp"

template <typename T>
class Deck : virtual public InventoryHolder
{
private:
    std::vector<T> buffer;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    Deck();
    void operator=(Deck<T> &);
    ~Deck();

    // === GETTER ==================================================
    int getLength() override;
    T getElmt(int);

    // === METHODS =================================================
    void push(const T &);
    void pop();
    void shuffle();
    T roll();
};

#endif