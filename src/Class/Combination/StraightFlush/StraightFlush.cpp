#include "StraightFlush.hpp"

StraightFlush::StraightFlush(std::vector<Card> cards)
{
    this->name = "StraightFlush";
    this->value = cards[0].getValue() * 0.1 + cards[1].getValue() * 0.01 + cards[2].getValue() * 0.001 + cards[3].getValue() * 0.001 + cards[4].getValue() * 0.0001 + 11.3955;//tambah yang 4kind
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