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

void GameState::displayTable()
{
    std::cout << "\n#-----============== TABLE ==============-----#\n"
              << std::endl;
    if (round == 1)
    {
        std::cout << "                  # # # # #" << std::endl;
    }
    else if (round < 6)
    {
        std::cout << "                  ";
        for (int i = 0; i < round - 1; i++)
        {
            this->table[i].displaycard();
            std::cout << " ";
        }
        for (int j = 0; j < 6 - round; j++)
        {
            std::cout << "# ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "                  ";
        for (int i = 0; i < 5; i++)
        {
            this->table[i].displaycard();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
}

void GameState::displayPlayer()
{
    std::cout << "\n#-----============ YOUR TURN ============-----#\n"
              << std::endl;
    std::cout << "\tName:\t" << this->players->getPlayerName(0) << std::endl;
    std::cout << "\tScore:\t" << this->players->getPlayerPoints(0) << std::endl;
    std::cout << "\tHands:\t";
    this->players->displayPlayerCards(0);
}

void GameState::startNewGame()
{
    this->game++;
    this->round = 1;

    // 1. Game Setup
    this->roll();
    this->rollTable();

    //
    // this->displayGameState();
    // for (int i = 0; i < this->players->getNumOfPlayers(); i++)
    // {
    //     // 2. Display player's hand
    //     this->players->displayPlayerCards(i);
    // }
    // std::cout << "====================" << std::endl;
    // this->playingDeck->displayDeck();
    // this->displayTable();
    // std::cin.get();

    // for (int i = 0; i < 5; i++)
    // {
    //     std::cin.get();
    //     this->startNewRound();
    // }

    //
}

void GameState::startNewRound()
{
    this->round++;
    this->prize = 64;
    this->turn = 1;
    this->displayGameState();
    for (int i = 0; i < this->players->getNumOfPlayers(); i++)
    {
        // 2. Display player's hand
        std::cout << "Player " << i + 1 << " Hand's" << std::endl;
        this->players->displayPlayerCards(i);
    }
    this->displayTable();
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

void GameState::roll()
{
    std::vector<Card> rolledCards;
    for (int i = 0; i < players->getNumOfPlayers(); i++)
    {
        rolledCards.push_back(this->playingDeck->drawCard());
        rolledCards.push_back(this->playingDeck->drawCard());
        players->setPlayerCards(i, rolledCards);
        rolledCards.clear();
    }
}

void GameState::rollTable()
{
    for (int i = 0; i < 5; i++)
    {
        this->table.push_back(this->playingDeck->drawCard());
    }
}

void GameState::nextTurn()
{
    this->players->roundRobin();
}

void GameState::nextRound()
{
    this->round++;
}

void GameState::playerAction()
{
    std::string action;
    std::string errMsg;
    bool isValid = false;

    while (!isValid)
    {

        this->displayGameState();
        this->displayTable();
        this->displayPlayer();

        std::cout << std::endl;

        std::cout << "\tAction menu:" << std::endl;
        std::cout << "\t1. Double" << std::endl;
        std::cout << "\t2. Next" << std::endl;
        std::cout << "\t3. Half" << std::endl;
        std::cout << "\t4. [Ability]" << std::endl; //
        std::cout << std::endl;

        try
        {
            std::cout << errMsg;
            std::cout << "\tAction: ";
            std::cin >> action;
            if (action == "1")
            {
                this->prize *= 2;
            }
            else if (action == "2")
            {
                // do nothing
            }
            else if (action == "3")
            {
                this->prize /= 2;
            }
            else if (action == "4")
            {
                // call ability
            }
            else
            {
                throw "\tAction is not available\n";
            }
            isValid = true;
        }
        catch (const char *err)
        {
            errMsg = err;
        }
    }
}
