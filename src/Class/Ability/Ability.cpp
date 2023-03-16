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
    else if (this->id == 3)
    {
        this->name = "Abilityless";
    }
    else if (this->id == 4)
    {
        this->name = "ReRoll";
    }
    else if (this->id == 5)
    {
        this->name = "Reverse";
    }
    else if (this->id == 6)
    {
        this->name = "Switch";
    }
    else if (this->id == 7)
    {
        this->name = "Swap";
    }
}

Ability::~Ability() {}

std::string Ability::getName()
{
    return this->name;
}