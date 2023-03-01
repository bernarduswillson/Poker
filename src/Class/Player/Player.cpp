#include "Player.hpp";

int Player::playerId = 0;

Player::Player() : id(playerId + 1)
{
    // Input player name
    bool isNameValid = false;
    std::cout << "\nInput player " << this->id << " name: " << std::endl;
    std::cin >> this->name;

    // Initialize point
    this->points = 0;

    // Initialize empty hands
    std::vector<Card> *hands = new std::vector<Card>;
    this->hands = *hands;

    // Initialize empty ability
    Ability *ability = new Ability();
    this->ability = *ability;

    // Initialize empty package
    Package *package = new Package();
    this->package = *package;
}
