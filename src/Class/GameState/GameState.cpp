#include <iostream>

#include "GameState.hpp"

GameState::GameState()
{
    this->game = 1;
    this->round = 1;
    this->prize = 64;
}

GameState::~GameState() {}

void GameState::displayGameState()
{
    std::cout << "\n#------===== GAME STATUS =====------#\n"
              << std::endl;
    std::cout << "Game:\t\t" << this->game << std::endl;
    std::cout << "Round:\t\t" << this->round << std::endl;
    std::cout << "Table Prize:\t" << this->prize << std::endl;
    displayLeaderboard();
}

void GameState::initializePlayers() {}

void GameState::displayLeaderboard()
{
    std::cout << "Leaderboard:" << std::endl;
}