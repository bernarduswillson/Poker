#ifndef __PLAYERLIST_HPP__
#define __PLAYERLIST_HPP__

#include <vector>
#include <string>

#include "../Player/Player.hpp"

class PlayerList
{
private:
    int numOfPlayers;
    std::vector<Player> playersBuffer;

public:
    PlayerList();
    ~PlayerList();

    int getNumOfPlayers();
    std::string getPlayerName(int);
    int getPlayerPoints(int);
    Player getPlayer(int);
    void addPlayer();
};

#endif