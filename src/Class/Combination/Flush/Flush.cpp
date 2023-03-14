#include "Flush.hpp"

Flush::Flush()
{
    this->name = "Flush";
}

Flush::~Flush()
{
}

double Flush::getValue()
{
    return this->value;
}

std::string Flush::getName()
{
    return this->name;
}

void Flush::setValue(double value)
{
    this->value = value;
}