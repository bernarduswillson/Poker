#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <vector>

#include "../Card/Card.hpp"

class Player
{
private:
    std::string name;
    long long int points;
    std::vector<Card> hands;
    bool isDisable;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    Player();
    void operator=(const Player &other);
    ~Player();

    // === GETTER SETTER ===========================================
    std::string getName();
    long long int getPoints();
    std::vector<Card> getHands();
    Card getHands(int idx);
    void setHands(std::vector<Card> hands);
    bool getIsDisable();
    void setIsDisable();

    // === OPERATOR OVERLOADING ====================================
    Player operator+(long long int addedPoints);
    Player operator+(Card addedCard);
    // void operator-(Card removedCard);

    // === METHOD ==================================================
    void inputName();
    // void findCombo(Package river);

    // === DISPLAY =================================================
    void displayHands();
};

#endif
