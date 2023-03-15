#include "Multiplier.hpp"

Multiplier::Multiplier(int id) : Ability(id) {}

Multiplier::~Multiplier() {}

long long int Multiplier::use(long long int prize)
{
    if (this->id == 1)
    {
        return 4 * prize;
    }
    return prize / 4;
}

void Multiplier::use(PlayerList &players, Deck<Card> &playingDeck) {}