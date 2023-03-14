#include "Pair.hpp"

Pair::Pair()
{
    this->name = "Pair";
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