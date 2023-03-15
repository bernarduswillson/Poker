#include "TwoPair.hpp"

TwoPair::TwoPair()
{
    this->name = "TwoPair";
}

TwoPair::~TwoPair()
{
}

double TwoPair::getValue()
{
    return this->value;
}

std::string TwoPair::getName()
{
    return this->name;
}

void TwoPair::setValue(double value)
{
    this->value = value;
}