#include "Player.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================
Player::Player()
{
    this->points = 0;
}

void Player::operator=(const Player &other)
{
    this->name = other.name;
    this->points = other.points;
    for (int i = 0; i < 2; i++)
    {
        this->hands[i] = other.hands[i];
    }
    // this->highestCombo = other.highestCombo;
}

Player::~Player() {}

// === GETTER SETTER ===========================================
std::string Player::getName()
{
    return this->name;
}

long long int Player::getPoints()
{
    return this->points;
}

std::vector<Card> Player::getHands()
{
    return this->hands;
}

Card Player::getHands(int idx)
{
    return this->hands[idx];
}

// === OPERATOR OVERLOADING ====================================
Player Player::operator+(long long int addedPoints)
{
    this->points += addedPoints;
    return *this;
}

Player Player::operator+(Card addedCard)
{
    this->hands.push_back(addedCard);
    return *this;
}

// void Player::operator-(Card removedCard) {

// }

// === METHOD ==================================================
void Player::inputName()
{
    std::string inputName;
    std::cout << "Enter player name: ";
    std::cin >> inputName;
    this->name = inputName;
}
// void findCombo(Package table) {

// }

// === DISPLAY =================================================
void Player::displayHands()
{
    // this->hands[0].displayCard();
    std::cout << this->hands[0].getNumber() << " " << this->hands[1].getNumber();
    // this->hands[1].displayCard();
}
