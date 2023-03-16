#ifndef __MULTIPLIER_HPP__
#define __MULTIPLIER_HPP__

#include "../Ability/Ability.hpp"

class Multiplier : virtual public Ability
{
public:
    Multiplier(int);
    ~Multiplier();

    long long int use(long long int) override;
    void use(PlayerList &, Deck<Card> &, int &) override;
};

#endif