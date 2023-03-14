#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <vector>

#include "../Card/Card.hpp"
// #include "../Calculable/Calculable.hpp"

class Player
{
private:
    std::string name;
    long long int points;
    std::vector<Card> hands;
    // Calculable highestCombo;

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
