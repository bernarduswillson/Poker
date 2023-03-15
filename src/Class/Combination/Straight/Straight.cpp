#include "Straight.hpp"

Straight::Straight(std::vector<Card> cards)
{
    this->name = "Straight";
    this->value = cards[0].getNumber()*0.1 + cards[0].getNumber()*0.03 + 5.65;
}

Straight::~Straight()
{
}

double Straight::getValue()
{
    return this->value;
}

std::string Straight::getName()
{
    return this->name;
}

void Straight::setValue(double value)
{
    this->value = value;
}