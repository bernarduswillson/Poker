#include "Player.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================
Player::Player()
{
    this->points = 0;
}

Player::~Player()
{
    // delete [] this->hands;
}

// === GETTER SETTER ===========================================
std::string Player::getName()
{
    return this->name;
}

long long int Player::getPoints()
{
    return this->points;
}

// === OPERATOR OVERLOADING ====================================
void Player::operator+(long long int addedPoints)
{
    this->points += addedPoints;
}

// void Player::operator+(Card addedCard) {

// }

// void Player::operator-(Card removedCard) {

// }

Player &Player::operator=(const Player &other)
{
    this->name = other.name;
    this->points = other.points;
    // this->hands = other.hands;
    // this->highestCombo = other.highestCombo;

    return *this;
}

// === METHOD ==================================================
void Player::inputName()
{
    std::string inputName;
    std::cout << "Enter player name: ";
    std::cin >> inputName;
    this->name = inputName;
}
// void findCombo(Package river) {

// }
