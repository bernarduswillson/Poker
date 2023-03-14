#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include "../Card/Card.cpp"
#include "../Calculable/Calculable.cpp"
#include "../Package/Package.hpp"
#include "../Combination/Pair/Pair.hpp"

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

    std::pair<bool, Card> isHigh(std::vector<Card> card);
    std::pair<bool, Card> isPair(std::vector<Card> card);
    std::pair<bool, Card> isTwoPair(std::vector<Card> card);
    std::pair<bool, Card> isThreeOfAKind(std::vector<Card> card);
    std::pair<bool, Card> isStraight(std::vector<Card> card);
    std::pair<bool, Card> isFlush(std::vector<Card> card);
    std::pair<bool, Card> isFullHouse(std::vector<Card> card);
    std::pair<bool, Card> isFourOfAKind(std::vector<Card> card);
    std::pair<bool, Card> isStraightFlush(std::vector<Card> card);
};

#endif
