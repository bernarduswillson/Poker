#define __CARD_HPP__
#include <iostream>
#include <string>

class Card {
    private:
        double value;
        std::string color;
        int number;
    public:
        Card();
        Card(int number, std::string color);
        double getValue();
        void displaycard();
};