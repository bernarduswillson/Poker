#include "Player.hpp"

int Player::num_players = 0;

Player::Player() : id(num_players + 1)
{
    std::string name;
    std::cout << "Enter player " << this->id << " name: ";
    std::cin >> name;
    this->name = name;
    this->points = 0;
    num_players++;
}

Player::~Player() {}

std::string Player::getName()
{
    return this->name;
}

int Player::getPoints()
{
    return this->points;
}

void Player::setHand(Card card)
{
    this->hand.push_back(card);
}
