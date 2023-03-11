#ifndef __DECK_HPP__
#define __DECK_HPP__

#include <vector>
#include <algorithm>

#include "../PlayerList/PlayerList.hpp"
#include "../Card/Card.hpp"

template <typename T>
class Deck
{
private:
    int length;
    std::vector<T> cardBuffer;

public:
    // Constructor and Destructor
    Deck();
    ~Deck();

    // Getter and Setter
    void getValues();

    // Methods
    void addCard(T card);
    void shuffle();
    // void roll(PlayerList &players, std::vector<T> &table);
    // void roll(Ability &ability);
    T drawCard();

    void displayDeck();
};

#endif