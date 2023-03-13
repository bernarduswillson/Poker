#include "Card.hpp"

Card::Card(double number, double color):Calculable()
{
    this->number = number;
    this->color = color;
    this->value = number * 0.1 + color * 0.03;
}

Card::~Card()
{
}

double Card::getValue()
{
    return this->value;
}

double Card::getNumber()
{
    return number;
}

double Card::getColor()
{
    return color;
}

void Card::setValue(double value)
{
    this->value = value;
}
