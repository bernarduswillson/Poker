#include "GameState.hpp"
#include "../Deck/Deck.cpp" // temporary solution

// === CONSTRUCTOR DESTRUCTOR ==================================

GameState::GameState()
{
    this->game = 0;
    this->round = 0;
    this->prize = 0;
    this->players = new PlayerList();
    this->playingDeck = new Deck<Card>;
    this->table = new Table();
}

GameState::~GameState()
{
    delete this->players;
    delete this->playingDeck;
    delete this->table;
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

void GameState::displayTable()
{
    std::cout << "\n#-----============== TABLE ==============-----#\n"
              << std::endl;
    this->table->display(this->round);
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
}

// === INITIALIZER =============================================

void GameState::initializePlayer()
{
    system("clear");
    std::cout << "\n##=========## WAITING FOR PLAYERS ##=========##\n"
              << std::endl;
    for (int i = 0; i < 7; i++)
    {
        Player *player = new Player();
        player->inputName();
        players->push(*player);
    }
}

void GameState::initializePlayingDeck()
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
        this->randomizeDeck();
    }
}

void GameState::randomizeDeck()
{
    for (int i = 1; i < 14; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card *newCard = new Card(i, j);
            this->playingDeck->push(*newCard);
        }
    }

    this->playingDeck->shuffle();

    for (int i = 0; i < 5; i++)
    {
        this->table->push(this->playingDeck->getElmt(i));
    }
}

// === GAME CONTROL ============================================

void GameState::newGame()
{
    // 1. Initialize game status
    this->game = 1;
    this->round = 1;
    this->prize = 64;

    // 2. Initialize players
    initializePlayer();

    // 3. Initialize deck
    initializePlayingDeck();
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