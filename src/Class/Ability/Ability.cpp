#include "Ability.hpp"

Ability::Ability()
{
    this->id = 0;
}

Ability::Ability(int id)
{
    if (this->id == 1)
    {
        this->name = "Quadruple";
    }
    else if (this->id == 2)
    {
        this->name = "Quarter";
    }
}

Ability::~Ability() {}

std::string Ability::getName()
{
    return this->name;
}