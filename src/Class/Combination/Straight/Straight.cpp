#include "Straight.hpp"

Straight::Straight()
{
    this->name = "Straight";
    this->value = cards[0].getValue()*1 + cards[1].getValue()*0.1 + cards[2].getValue()*0.01 + cards[3].getValue()*0.001 + cards[4].getValue()*0.0001 +5.65;
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