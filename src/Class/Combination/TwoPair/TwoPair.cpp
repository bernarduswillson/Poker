#include "TwoPair.hpp"

TwoPair::TwoPair(std::vector<Card> cards)
{
    this->name = "TwoPair";
    this->value = cards[0].getValue()*0.1 + cards[1].getValue()*0.01 + cards[2].getValue()*0.001 + cards[3].getValue()*0.0001 + 1.5426;
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