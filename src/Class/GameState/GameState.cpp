#include <iostream>

#include "GameState.hpp"
#include "../Deck/Deck.cpp" // temporary solution

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

    // 3. Initialize deck of playing cards
    this->initializeDeck();
}

GameState::~GameState()
{
    delete this->players;
    delete this->playingDeck;
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

void GameState::initializeDeck()
{
    bool isMenuValid = false;
    std::string menu;
    std::string errMsg;

    while (!isMenuValid)
    {
        system("clear");
        std::cout << "\n#-----======= PLAYING DECK OPTION =======-----#\n"
                  << std::endl;
        std::cout << "                1. Generate random" << std::endl;
        std::cout << "             2. Import from text file" << std::endl;
        std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
                  << std::endl;

        std::cout << errMsg;

        try
        {
            std::cout << "Select menu: ";
            std::cin >> menu;

            if (menu != "1" && menu != "2")
            {
                throw "Menu not available\n";
            }

            isMenuValid = true;
        }
        catch (const char *err)
        {
            errMsg = err;
        }
        catch (...)
        {
            errMsg = "Menu invalid\n";
        }
    }

    if (menu == "1")
    {
        this->initializeRandomDeck();
    }
}

void GameState::initializeRandomDeck()
{
    this->playingDeck = new Deck<Card>();

    for (int i = 1; i < 14; i++)
    {
        Card *newCard = new Card(i, "red");
        this->playingDeck->addCard(*newCard);
    }

    for (int i = 1; i < 14; i++)
    {
        Card *newCard = new Card(i, "yellow");
        this->playingDeck->addCard(*newCard);
    }

    for (int i = 1; i < 14; i++)
    {
        Card *newCard = new Card(i, "blue");
        this->playingDeck->addCard(*newCard);
    }

    for (int i = 1; i < 14; i++)
    {
        Card *newCard = new Card(i, "green");
        this->playingDeck->addCard(*newCard);
    }

    this->playingDeck->shuffle();
}