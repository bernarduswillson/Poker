#include "TwoPair.hpp"

TwoPair::TwoPair(std::vector<Card> cards)
{
    this->name = "TwoPair";
    this->value = cards[0].getNumber()*0.1 + cards[0].getColor()*0.03 + 2.78;
}

TwoPair::~TwoPair()
{
}

double TwoPair::getValue()
{
    return this->value;
}

std::string TwoPair::getName()
{
    return this->name;
}

void TwoPair::setValue(double value)
{
    this->value = value;
}