#include "FullHouse.hpp"

FullHouse::FullHouse(std::vector<Card> cards)
{
    this->name = "FullHouse";
    this->value = cards[0].getNumber()*0.1 + cards[0].getColor()*0.03 + cards[1].getColor()*0.03 + cards[2].getColor()*0.03 + (cards[3].getNumber()*0.1 + cards[3].getColor()*0.03)*0.001+ 6.14079;
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