#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(std::vector<Card> cards)
{
    this->name = "FourOfAKind";
    this->value = cards[0].getNumber()*0.1+10.2521;//tambah flush
}

FourOfAKind::~FourOfAKind()
{
}

double FourOfAKind::getValue()
{
    return this->value;
}

std::string FourOfAKind::getName()
{
    return this->name;
}

void FourOfAKind::setValue(double value)
{
    this->value = value;
}