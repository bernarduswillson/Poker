#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
// #include "../Card/Card.hpp"
// #include "../Calculable/Calculable.hpp"

class Player
{
private:
    std::string name;
    long long int points;
    // Card* hands;
    // Calculable highestCombo;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    Player();
    ~Player();

    // === GETTER SETTER ===========================================
    std::string getName();
    long long int getPoints();

    // === OPERATOR OVERLOADING ====================================
    void operator+(long long int addedPoints);
    // void operator+(Card addedCard);
    // void operator-(Card removedCard);
    Player &operator=(const Player &other);

    // === METHOD ==================================================
    void inputName();
    // void findCombo(Package river);
};

#endif
