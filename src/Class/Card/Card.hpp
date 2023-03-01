#define __CARD_HPP__
#include <iostream>
#include <string>

class Card {
    private:
        double value;
    public:
        Card();
        Card(double number, std::string color);
        double getValue();
};