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
    // Constructor and Destructor
    PlayerList();
    ~PlayerList();

    // Getter and Setter
    int getNumOfPlayers();
    std::string getPlayerName(int);
    int getPlayerPoints(int);
    Player getPlayer(int);

    // Methods
    void addPlayer();
    void setPlayerCards(int, std::vector<Card>);
    void displayPlayerCards(int);
};

#endif