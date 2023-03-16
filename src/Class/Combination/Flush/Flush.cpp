#include "Flush.hpp"

Flush::Flush(std::vector<Card> cards)
{
    this->name = "Flush";
    this->value = cards[0].getNumber()*0.1 + cards[1].getNumber()*0.01 + cards[2].getNumber()*0.001 + cards[3].getNumber()*0.0001 + cards[4].getNumber()*0.00001 + 7.18209;//+straight
}

Flush::~Flush()
{
}

double Flush::getValue()
{
    return this->value;
}

std::string Flush::getName()
{
    return this->name;
}

void Flush::setValue(double value)
{
    this->value = value;
}