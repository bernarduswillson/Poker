#include "Ability.hpp"

Ability::Ability()
{
    this->id = 0;
}

Ability::Ability(int id)
{
    this->id = id;
    if (this->id == 1)
    {
        this->name = "Quadruple";
    }
    else if (this->id == 2)
    {
        this->name = "Quarter";
    }
    else if (this->id == 2)
    {
        this->name = "Abilityless";
    }
}

Ability::~Ability() {}

std::string Ability::getName()
{
    return this->name;
}