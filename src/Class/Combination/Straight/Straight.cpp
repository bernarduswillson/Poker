#include "Straight.hpp"

Straight::Straight()
{
    this->name = "Straight";
}

Straight::~Straight()
{
}

double Straight::getValue()
{
    return this->value;
}

std::string Straight::getName()
{
    return this->name;
}

void Straight::setValue(double value)
{
    this->value = value;
}