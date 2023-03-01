#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>

// #include "../Card/Card.hpp"

template <typename T>
class Deck
{
private:
    int length;
    std::vector<T> cardBuffer;

public:
    Deck();
    ~Deck();
    void addCard(T card);
    void shuffle();
    void roll();
    void getValues();
};

#endif