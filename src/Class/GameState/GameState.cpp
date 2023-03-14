#include "GameState.hpp"
#include "../Deck/Deck.cpp" // temporary solution

// === CONSTRUCTOR DESTRUCTOR ==================================

GameState::GameState()
{
    this->game = 0;
    this->round = 0;
    this->prize = 0;
    this->target = 0;
    this->ongoing = false;
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

// === GETTER SETTER ===========================================
bool GameState::isOngoing()
{
    return this->ongoing;
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

void GameState::displayWinner()
{
    std::cout << "\n#-----======= CONGRATULATION !!! ========-----#\n"
              << std::endl;
    std::cout << this->winner.getName() << " wins the game with " << this->winner.getPoints() << " points!" << std::endl;
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

void GameState::rollPlayingCard()
{
    std::vector<Card> temp;
    for (int j = 0; j < 2; j++)
    {
        std::vector<Card> rolledCards;
        for (int i = 0; i < 7; i++)
        {
            rolledCards.push_back(this->playingDeck->roll());
            rolledCards.push_back(this->playingDeck->roll());
            players->setPlayerCards(i, rolledCards);
            rolledCards.clear();
        }
    }

    for (int i = 0; i < 5; i++)
    {
        this->table->push(this->playingDeck->getElmt(0));
        this->playingDeck->pop();
    }
}

void GameState::evaluateGameWinner()
{
    for (int i = 0; i < 7; i++)
    {
        if (this->players->getElmt(i).getPoints() >= this->target)
        {
            this->ongoing = false;
            this->winner = this->players->getElmt(i);
        }
    }
}

// === GAME CONTROL ============================================

void GameState::newGame()
{
    // 1. Initialize game status
    this->game = 1;
    this->round = 1;
    this->prize = 64;
    this->target = 4294967296;
    this->ongoing = true;

    // 2. Initialize players
    initializePlayer();

    // 3. Initialize deck
    initializePlayingDeck();

    // 4. Roll playing cards
    rollPlayingCard();
}

void GameState::nextTurn()
{
    this->players->roundRobin();
    long long int temp = 4294967296;
    this->players->getElmt(0) = this->players->getElmt(0) + temp;
}

void GameState::nextRound()
{
    this->round++;
}

void GameState::nextGame()
{
    this->evaluateGameWinner();
    this->game++;
    this->round = 1;
    this->prize = 64;
}

void GameState::playerAction()
{
    std::string action;
    std::string errMsg;
    bool isValid = false;

    while (!isValid)
    {

        std::cout << "\n#-----=========== PLAYER TURN ===========-----#\n"
                  << std::endl;
        std::cout << "Name:\t" << this->players->getElmt(0).getName() << std::endl;
        std::cout << "Points:\t" << this->players->getElmt(0).getPoints() << std::endl;
        std::cout << "Hands:\t";
        this->players->getElmt(0).displayHands();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Action menu:" << std::endl;
        std::cout << "1. Double" << std::endl;
        std::cout << "2. Next" << std::endl;
        std::cout << "3. Half" << std::endl;
        std::cout << "4. [Ability]" << std::endl; //
        std::cout << std::endl;

        try
        {
            std::cerr << errMsg;
            std::cout << "Action: ";
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
                if (this->prize != 1)
                {
                    this->prize /= 2;
                }
            }
            else if (action == "4")
            {
                // call ability
            }
            else
            {
                throw "Action is not available\n";
            }
            isValid = true;
        }
        catch (const char *err)
        {
            errMsg = err;
        }
    }
}