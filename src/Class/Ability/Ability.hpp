#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include <string>

#include "../PlayerList/PlayerList.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"

class Ability
{
protected:
    int id;
    std::string name;

public:
    Ability();
    Ability(int);
    ~Ability();

    std::string getName();

    virtual long long int use(long long int) = 0;
    virtual void use(PlayerList &, Deck<Card> &) = 0;
};

#endif