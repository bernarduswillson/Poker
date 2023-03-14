#include "Calculable.hpp"

Calculable::Calculable()
{
    // this->value = value;
}

Calculable::~Calculable()
{
}

bool Calculable::operator>(Calculable &obj)
{
    return value > obj.value;
}

bool Calculable::operator<(Calculable &obj)
{
    return value < obj.value;
}

bool Calculable::operator=(Calculable &obj)
{
    return value == obj.value;
}
