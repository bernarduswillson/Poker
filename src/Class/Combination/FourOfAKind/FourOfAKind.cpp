#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind()
{
    this->name = "FourOfAKind";
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