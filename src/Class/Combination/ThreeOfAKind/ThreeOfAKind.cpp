#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(std::vector<Card> cards)
{
    this->name = "ThreeOfAKind";
    this->value = cards[0].getNumber()*0.1 + cards[0].getColor()*0.03 + cards[1].getColor()*0.03 + cards[2].getColor()*0.03 + 4.17;
}

ThreeOfAKind::~ThreeOfAKind()
{
}

double ThreeOfAKind::getValue()
{
    return this->value;
}

std::string ThreeOfAKind::getName()
{
    return this->name;
}

void ThreeOfAKind::setValue(double value)
{
    this->value = value;
}