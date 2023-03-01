#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"
#include "../Package/Package.hpp"
#include "../GameState/GameState.hpp"

class Player
{
private:
    int id;
    std::string name;
    int points;
    std::vector<Card> hands;
    Ability ability;
    Package package;

    static int playerId;

public:
    Player();
    ~Player();
};

#endif