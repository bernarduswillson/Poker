#include "FullHouse.hpp"

FullHouse::FullHouse(std::vector<Card> cards)
{
    this->name = "FullHouse";
    for (int i = 0; i < cards.size(); i++) {
        std::cout << cards[i].getNumber() << " " << cards[i].getColor() << std::endl;
    }
    this->value = cards[0].getNumber()*0.1 + cards[0].getColor()*0.03 + cards[1].getColor()*0.03 + cards[2].getColor()*0.03 + 8.61417;
}

FullHouse::~FullHouse()
{
}

double FullHouse::getValue()
{
    return this->value;
}

std::string FullHouse::getName()
{
    return this->name;
}

void FullHouse::setValue(double value)
{
    this->value = value;
}