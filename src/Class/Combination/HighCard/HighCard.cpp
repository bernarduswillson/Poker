#include "HighCard.hpp"

HighCard::HighCard(std::vector<Card> cards)
{
    this->name = "HighCard";
    this->value = cards[0].getValue();
}

HighCard::~HighCard()
{
}

double HighCard::getValue()
{
    return this->value;
}

std::string HighCard::getName()
{
    return this->name;
}

void HighCard::setValue(double value)
{
    this->value = value;
}