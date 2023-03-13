#include "Card.hpp"

Card::Card():Calculable()
{
    number = 0;
    color = "none";
}

Card::~Card()
{
}

double Card::getValue()
{
    return this->value;
}

int Card::getNumber()
{
    return number;
}

std::string Card::getColor()
{
    return color;
}

void Card::setValue(double value)
{
    this->value = value;
}
