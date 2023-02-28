#include <iostream>
#include <vector>
#include "Deck.hpp"

class AbilityDeck : public Deck {
    private:
        std::vector<int> cardBuffer;
    public:
        AbilityDeck();
        void shuffle();
};