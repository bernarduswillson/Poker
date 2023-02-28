#include <iostream>
#include <vector>

class Deck {
    private:
        std::vector<int> cardBuffer;
    public:
        Deck();
        void shuffle();
};