#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include "../Card/Card.cpp"
#include "../Calculable/Calculable.cpp"
#include "../Package/Package.cpp"
#include "../Combination/Pair/Pair.cpp"
#include "../Table/Table.cpp"
#include "../InventoryHolder/InventoryHolder.cpp"

class Player
{
private:
    std::string name;
    long long int points;
    std::vector<Card> hands;
    Package highestCombo;

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
    void findCombo(Table river);

    std::pair<bool, std::vector<Card>> isHigh(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isPair(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isTwoPair(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isThreeOfAKind(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isStraight(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFlush(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFullHouse(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFourOfAKind(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isStraightFlush(std::vector<Card> card);

    void displayHands();

    Package getHighestCombo();
};

#endif
