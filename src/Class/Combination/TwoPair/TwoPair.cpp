#include "TwoPair.hpp"

TwoPair::TwoPair(Card maxCard)
{
    this->name = "TwoPair";
    this->value = maxCard.getNumber()*0.1 + maxCard.getColor()*0.03 + 2.78;
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