#ifndef __PLAYER_MANIPULATION_HPP__
#define __PLAYER_MANIPULATION_HPP__

#include <iostream>
#include "../Ability/Ability.hpp"
#include "../Exception/Exception.hpp"

class PlayerManipulation : virtual public Ability
{
public:
    PlayerManipulation(int);
    ~PlayerManipulation();

    long long int use(long long int) override;
    void use(PlayerList &, Deck<Card> &, int &) override;
};

#endif