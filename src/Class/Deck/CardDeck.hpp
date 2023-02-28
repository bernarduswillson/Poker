#include <iostream>
#include <vector>
#include "Deck.hpp"

class CardDeck : public Deck {
    private:
        std::vector<int> cardBuffer;
    public:
        CardDeck();
        void shuffle();
};