#include <iostream>

#include "GameState.hpp"

GameState::GameState()
{
    this->game = 0;
    this->round = 0;
    this->prize = 64;
    this->turn = 1;

    // 1. Display splash
    this->displaySplash();

    // 2. Initialize players
    this->initializePlayers();
}

GameState::~GameState()
{
    delete this->players;
}

void GameState::displaySplash()
{
    system("clear");
    std::cout << "\n##=======## CANDY KINGDOM CARD GAME ##=======##\n"
              << std::endl;
    std::cout << "           Created by Kebo Ngibrit            " << std::endl;
    std::cout
        << "\n#-----=====#*#========#@#========#*#=====-----#\n"
        << std::endl;
    std::cout << "          Press any key to start...           " << std::endl;
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

void GameState::displayLeaderboard() /* ditra: belum disort */
{
    std::cout << "\n#-----=========== LEADERBOARD ===========-----#\n"
              << std::endl;
    for (int i = 0; i < this->players->getNumOfPlayers(); i++)
    {
        std::cout << i + 1 << ". " << this->players->getPlayerName(i) << " (" << this->players->getPlayerPoints(i) << " points)" << std::endl;
    }
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
}

void GameState::startNewGame()
{
    this->game++;
    this->round = 1;

    // 1. Display game status
    this->displayGameState();
}
void GameState::initializePlayers()
{
    system("clear");
    std::cout << "\n#-----======= WAITING FOR PLAYERS =======-----#\n"
              << std::endl;
    this->players = new PlayerList();
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
}