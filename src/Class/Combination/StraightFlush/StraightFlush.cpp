#include "StraightFlush.hpp"

StraightFlush::StraightFlush(std::vector<Card> cards)
{
    this->name = "StraightFlush";
    this->value = cards[0].getColor() * 0.03 + cards[0].getNumber() * 0.1 + 11.5521;//tambah yang 4kind
}

StraightFlush::~StraightFlush()
{
}

double StraightFlush::getValue()
{
    return this->value;
}

std::string StraightFlush::getName()
{
    return this->name;
}

void StraightFlush::setValue(double value)
{
    this->value = value;
}