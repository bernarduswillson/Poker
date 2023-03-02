#include "PlayerList.hpp"

PlayerList::PlayerList()
{
    numOfPlayers = 0;
    for (int i = 0; i < 7; i++) {
        addPlayer();
        numOfPlayers++;
    }
}

PlayerList::~PlayerList()
{}

void PlayerList::addPlayer()
{
    playersBuffer.push_back(Player());
}

// int PlayerList::getNumOfPlayers()
// {
//     return numOfPlayers;
// }