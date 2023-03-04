#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <string>

class Player
{
private:
    const int id;
    std::string name;
    int points;

    static int num_players;

public:
    Player();
    ~Player();

    std::string getName();
    int getPoints();
};

#endif