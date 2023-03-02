#ifndef __PLAYERLIST_HPP__
#define __PLAYERLIST_HPP__

#include <iostream>
#include "../Player/Player.cpp"

class PlayerList
{
private:
    int numOfPlayers;
    std::vector<Player> playersBuffer;

public:
    PlayerList();
    ~PlayerList();
    void addPlayer();
    // int getNumOfPlayers();
};

#endif