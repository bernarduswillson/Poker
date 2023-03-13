#include "GameState.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================

GameState::GameState()
{
    this->game = 0;
    this->round = 0;
    this->prize = 0;
}

GameState::~GameState()
{
}

// === DISPLAY =================================================

void GameState::displaySplash()
{
    system("clear");
    std::cout << "\n##=======## CANDY KINGDOM CARD GAME ##=======##\n"
              << std::endl;
    std::cout << "           Created by Kebo Ngibrit            " << std::endl;
    std::cout
        << "\n#-----=====#*#========#@#========#*#=====-----#\n"
        << std::endl;
    std::cout << "            Press enter to start...           " << std::endl;
    std::cin.get();
}

void GameState::displayGameState()
{
    system("clear");
    std::cout << "\n##=======## CANDY KINGDOM CARD GAME ##=======##\n"
              << std::endl;
    std::cout << "Game:\t\t" << this->game << std::endl;
    std::cout << "Round:\t\t" << this->round << std::endl;
    std::cout << "Table prize:\t" << this->prize << " points" << std::endl;
    std::cout
        << "\n#-----=====#*#========#@#========#*#=====-----#\n"
        << std::endl;
}

// === GAME CONTROL ============================================

void GameState::newGame()
{
    // 1. Initialize game status
    this->game = 1;
    this->round = 1;
    this->prize = 64;
}

void GameState::nextRound()
{
    this->round++;
}

void GameState::nextGame()
{
    this->game++;
    this->round = 1;
    this->prize = 64;
}