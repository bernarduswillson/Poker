#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <string>
#include "../Card/Card.hpp"

class Player
{
private:
    const int id;
    std::string name;
    int points;
    vector<Card> hand;
    static int num_players;

public:
    Player();
    ~Player();

    std::string getName();
    int getPoints();
    void setHand(Card card);
};

#endif