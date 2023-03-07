#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "../Card/Card.hpp"

class Player
{
private:
    const int id;
    std::string name;
    int points;
    std::vector<Card> hand;
    static int num_players;

public:
    // Constructor and Destructor
    Player();
    ~Player();

    // Getter and Setter
    std::string getName();
    int getPoints();
    void setHand(Card card);
};

#endif