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
        std::string name;
        int points;

        const int id;
        static int num_players;

    public:
        Player();
        ~Player();
        void displayPlayer();
};

#endif