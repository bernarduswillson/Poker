#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind()
{
    this->name = "ThreeOfAKind";
}

ThreeOfAKind::~ThreeOfAKind()
{
}

double ThreeOfAKind::getValue()
{
    return this->value;
}

std::string ThreeOfAKind::getName()
{
    return this->name;
}

void ThreeOfAKind::setValue(double value)
{
    this->value = value;
}