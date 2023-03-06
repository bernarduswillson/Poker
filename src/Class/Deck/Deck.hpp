#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>
#include "../PlayerList/PlayerList.hpp"
#include "../Card/Card.hpp"


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
    void roll(PlayerList &players, std::vector <T> &table);
    // void roll(Ability &ability);
    void getValues();
};

#endif