#include "Player.hpp"

int Player::num_players = 0;

Player::Player() : id(num_players + 1) {
    std::string name;
    std::cout << "Input Player Name: ";
    std::cin >> name;
    std::cout << std::endl;
    this->name = name;
    this->points = 0;
    num_players++;
}

Player::~Player() {
}

void Player::displayPlayer() {
    std::cout << this->name << "(" << this->points << ")" << std::endl;
}