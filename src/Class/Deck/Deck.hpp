#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>

#include "Card.hpp"

template <typename T>
class Deck
{
private:
    int length;
    std::vector<T> cardBuffer;

public:
    Deck();
    ~Deck();
    void shuffle();
    void roll();
};

#endif