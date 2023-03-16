#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include "../Card/Card.hpp"
#include "../Calculable/Calculable.hpp"
#include "../Package/Package.hpp"
#include "../Combination/Pair/Pair.hpp"
#include "../Combination/TwoPair/TwoPair.hpp"
#include "../Combination/ThreeOfAKind/ThreeOfAKind.hpp"
#include "../Combination/Straight/Straight.hpp"
#include "../Combination/Flush/Flush.hpp"
#include "../Combination/FullHouse/FullHouse.hpp"
#include "../Combination/FourOfAKind/FourOfAKind.hpp"
#include "../Combination/StraightFlush/StraightFlush.hpp"
#include "../Combination/HighCard/HighCard.hpp"
#include "../Table/Table.hpp"
#include "../InventoryHolder/InventoryHolder.hpp"

class Player
{
private:
    std::string name;
    long long int points;
    std::vector<Card> hands;
    bool isDisable;
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
    bool getIsDisable();
    void setIsDisable();
    Package getHighestCombo();

    // === OPERATOR OVERLOADING ====================================
    Player operator+(long long int addedPoints);
    Player operator+(Card addedCard);

    // === METHOD ==================================================
    void inputName();
    void findCombo(Table river);

    std::vector<Card> sortCard(std::vector<Card> card);
    void resetHands();

    std::pair<bool, std::vector<Card>> isHigh(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isPair(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isTwoPair(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isThreeOfAKind(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isStraight(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFlush(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFullHouse(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isFourOfAKind(std::vector<Card> card);
    std::pair<bool, std::vector<Card>> isStraightFlush(std::vector<Card> card);

    // === DISPLAY =================================================
    void displayHands();
};

#endif
