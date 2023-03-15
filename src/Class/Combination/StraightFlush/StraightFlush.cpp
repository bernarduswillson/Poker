#include "StraightFlush.hpp"

StraightFlush::StraightFlush(std::vector<Card> cards)
{
    this->name = "StraightFlush";
    this->value = cards[0].getValue()+0;//tambah yang 4kind
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