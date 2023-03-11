#include "PlayerList.hpp"

PlayerList::PlayerList()
{
    numOfPlayers = 0;
    for (int i = 0; i < 7; i++)
    {
        this->addPlayer();
    }
}

PlayerList::~PlayerList()
{
}

int PlayerList::getNumOfPlayers()
{
    return this->numOfPlayers;
}

std::string PlayerList::getPlayerName(int idx)
{
    return this->playersBuffer[idx].getName();
}

int PlayerList::getPlayerPoints(int idx)
{
    return this->playersBuffer[idx].getPoints();
}

Player PlayerList::getPlayer(int idx)
{
    return this->playersBuffer[idx];
}

void PlayerList::addPlayer()
{
    this->playersBuffer.push_back(Player());
    numOfPlayers++;
}

void PlayerList::setPlayerCards(int idx, std::vector<Card> cards)
{
    this->playersBuffer[idx].setHand(cards);
}

void PlayerList::displayPlayerCards(int idx)
{
    this->playersBuffer[idx].displayHand();
}

// int PlayerList::getNumOfPlayers()
// {
//     return numOfPlayers;
// }