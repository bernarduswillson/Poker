#include "Multiplier.hpp"

Multiplier::Multiplier(int id) : Ability(id)
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
}

Multiplier::~Multiplier() {}

long long int Multiplier::use(long long int prize)
{
    if (this->id == 1)
    {
        return 4 * prize;
    }
    return prize / 4;
}