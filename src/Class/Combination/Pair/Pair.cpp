#include "Pair.hpp"

Pair::Pair(std::vector<Card> cards)
{
    //sort cards using greater or less than operator
    this->name = "Pair";
    this->value = cards[0].getNumber()*0.1 + cards[0].getColor()*0.03 + 1.39;
}

Pair::~Pair()
{
}

double Pair::getValue()
{
    return this->value;
}

std::string Pair::getName()
{
    return this->name;
}

void Pair::setValue(double value)
{
    this->value = value;
}