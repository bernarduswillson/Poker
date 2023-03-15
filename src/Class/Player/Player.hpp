#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include "../Card/Card.cpp"
#include "../Calculable/Calculable.cpp"
#include "../Package/Package.cpp"
#include "../Combination/Pair/Pair.cpp"
#include "../Combination/TwoPair/TwoPair.cpp"
#include "../Combination/ThreeOfAKind/ThreeOfAKind.cpp"
#include "../Combination/Straight/Straight.cpp"
#include "../Combination/Flush/Flush.cpp"
#include "../Combination/FullHouse/FullHouse.cpp"
#include "../Combination/FourOfAKind/FourOfAKind.cpp"
#include "../Combination/StraightFlush/StraightFlush.cpp"
#include "../Combination/HighCard/HighCard.cpp"
#include "../Table/Table.cpp"
#include "../InventoryHolder/InventoryHolder.cpp"

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
