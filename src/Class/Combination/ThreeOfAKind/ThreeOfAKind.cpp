#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(Card maxCard)
{
    this->name = "ThreeOfAKind";
    this->value = maxCard.getNumber()*0.1 + maxCard.getColor()*0.03 + 1.39;
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