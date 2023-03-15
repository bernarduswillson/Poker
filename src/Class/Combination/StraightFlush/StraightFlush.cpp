#include "StraightFlush.hpp"

StraightFlush::StraightFlush()
{
    this->name = "StraightFlush";
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