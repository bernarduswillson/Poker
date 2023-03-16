#include "GameState.hpp"
#include "../Deck/Deck.cpp"     // temporary solution
#include "../GArray/GArray.cpp" // temporary solution

// === CONSTRUCTOR DESTRUCTOR ==================================

GameState::GameState()
{
    this->game = 0;
    this->round = 0;
    this->turn = 0;
    this->prize = 0;
    this->target = 0;
    this->ongoing = false;
    this->players = new PlayerList();
    this->playingDeck = new Deck<Card>;
    this->abilityDeck = new Deck<Ability *>;
    this->table = new Table();
    this->winner = new Player();
}

GameState::~GameState()
{
    delete this->players;
    delete this->playingDeck;
    delete this->table;
    delete this->abilityDeck;
    delete this->winner;
}

// === GETTER SETTER ===========================================

void GameState::setPrize(long long int newPrize)
{
    this->prize = newPrize;
}

long long int GameState::getPrize()
{
    return this->prize;
}

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
    std::cout << "Turn:\t\t" << this->turn << std::endl;
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
    std::cout << this->winner->getName() << " wins the game with " << this->winner->getPoints() << " points!" << std::endl;
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
    std::cin.clear();
    std::cin.get();
}

void GameState::displayLeaderboard()
{
    std::vector<Player> leaderboard;
    for (int i = 0; i < 7; i++)
    {
        leaderboard.push_back(this->players->getElmt(i));
    }
    std::sort(leaderboard.begin(), leaderboard.end());
    std::reverse(leaderboard.begin(), leaderboard.end());

    system("clear");
    std::cout << "\n#-----=========== LEADERBOARD ===========-----#\n"
              << std::endl;
    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            std::cout << "[1st]\t";
        }
        else if (i == 1)
        {
            std::cout << "[2nd]\t";
        }
        else if (i == 2)
        {
            std::cout << "[3rd]\t";
        }
        else
        {
            std::cout << i + 1 << ".\t";
        }
        std::cout << leaderboard[i].getName() << " (" << leaderboard[i].getPoints() << ") with " << leaderboard[i].getHighestCombo()->getName();
        // std::cout << this->players->getElmt(i).getHighestCombo()->getValue();
        std::cout << std::endl;
    }
    std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
              << std::endl;
    std::cout << "          Press enter to continue...           " << std::endl;
    std::cin.ignore();
    std::cin.get();
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
        std::cout << "              1. Generate random" << std::endl;
        std::cout << "           2. Import from text file" << std::endl;
        std::cout << "\n#-----=====#*#========#@#========#*#=====-----#\n"
                  << std::endl;

        std::cout << errMsg;

        try
        {
            std::cout << "Select menu: ";
            std::cin >> menu;

            if (menu != "1" && menu != "2")
            {
                throw MenuException();
            }

            isMenuValid = true;
        }
        catch (MenuException err)
        {
            errMsg = err.what();
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
    else if (menu == "2")
    {
        this->generateDeckTxt();
        std::cout << this->playingDeck->getLength() << std::endl;
        this->playingDeck->getElmt(0).displayCard();
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
}

void GameState::generateDeckTxt()
{
    std::ifstream infile("./config/deck.txt");
    int a, b;
    std::vector<std::pair<int, int>> vec;

    while (infile >> a >> b)
    {
        vec.push_back(std::make_pair(a, b));
    }

    for (auto p : vec)
    {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    }

    for (auto p : vec)
    {
        std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
        Card *newCard = new Card(p.first, p.second);
        this->playingDeck->push(*newCard);
    }
}

void GameState::rollPlayingCard()
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

void GameState::initializeAbilityDeck()
{

    Multiplier *quadruple = new Multiplier(1);
    this->abilityDeck->push(quadruple);

    Multiplier *quarter = new Multiplier(2);
    this->abilityDeck->push(quarter);

    PlayerManipulation *abiliyless = new PlayerManipulation(3);
    this->abilityDeck->push(abiliyless);

    PlayerManipulation *reroll = new PlayerManipulation(4);
    this->abilityDeck->push(reroll);

    PlayerManipulation *reverse = new PlayerManipulation(5);
    this->abilityDeck->push(reverse);

    PlayerManipulation *sitch = new PlayerManipulation(6);
    this->abilityDeck->push(sitch);

    PlayerManipulation *swap = new PlayerManipulation(7);
    this->abilityDeck->push(swap);

    this->abilityDeck->shuffle();
}

void GameState::rollAbility()
{
    for (int i = 0; i < 7; i++)
    {
        this->playersAbility[this->players->getElmt(i).getName()] = this->abilityDeck->getElmt(i);
    }
}

void GameState::evaluateWinner()
{
    GArray<Package> playersPackage;
    for (int i = 0; i < 7; i++)
    {
        playersPackage.push(*this->players->getElmt(i).getHighestCombo());
        std::cout << playersPackage.getElmt(i).getName() << std::endl;
    }
    int winnerIdx = playersPackage.getIdxMax();

    this->players->getElmt(winnerIdx) = this->players->getElmt(winnerIdx) + this->prize;
}

void GameState::evaluateGameWinner()
{
    std::cout << "Evaluate game winner running" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << "Evaluate game loop" << std::endl;
        std::cout << this->players->getElmt(i).getPoints() << std::endl;
        if (this->players->getElmt(i).getPoints() >= this->target)
        {
            this->ongoing = false;
            std::cout << "Menang ea" << std::endl;
            this->winner = &this->players->getElmt(i);
            std::cout << "Menang ea 2" << std::endl;
        }
    }
    std::cout << "Evaluate game winner finished" << std::endl;
}

// === GAME CONTROL ============================================

void GameState::newGame()
{
    // 1. Initialize game status
    this->game = 1;
    this->round = 1;
    this->turn = 1;
    this->prize = 64;
    this->target = 4294967296;
    this->ongoing = true;

    // 2. Initialize players
    initializePlayer();
    for (int i = 0; i < 7; i++)
    {
        if (!this->players->getElmt(i).getIsDisable())
        {
            this->players->getElmt(i).setIsDisable();
        }
    }
    this->table->push(Card(20, 20));

    // 3. Initialize deck
    initializePlayingDeck();

    // 4. Roll playing cards
    rollPlayingCard();

    // 5. Initialize ability
    initializeAbilityDeck();

    // 6. Roll ability
    rollAbility();
}

void GameState::nextTurn()
{
    this->turn++;
    this->players->roundRobin();
}

void GameState::nextRound()
{
    this->round++;
    this->turn = 1;

    if (round == 2)
    {
        this->table->pop();
        for (int i = 0; i < 7; i++)
        {
            if (this->players->getElmt(i).getIsDisable())
            {
                this->players->getElmt(i).setIsDisable();
            }
        }
    }
    this->players->roundRobin();
    this->table->push(this->playingDeck->roll());
}

void GameState::nextGame()
{
    this->evaluateWinner();
    this->displayLeaderboard();
    this->evaluateGameWinner();

    // 1.1 Reset game status
    this->game++;
    this->round = 1;
    this->turn = 1;
    this->prize = 64;

    // 1.2 Reset table
    delete this->table;
    this->table = new Table();
    this->table->push(Card(20, 20));

    // 1.3 Reset playing deck
    delete this->playingDeck;
    this->playingDeck = new Deck<Card>;

    // 1.4 Reset ability deck
    delete this->abilityDeck;
    this->abilityDeck = new Deck<Ability *>;

    // 1.5 Initialize ability
    initializeAbilityDeck();

    // 1.6 Roll ability
    rollAbility();

    // 2.1 Reset players hands
    for (int i = 0; i < 7; i++)
    {
        this->players->getElmt(i).resetHands();
    }

    // 2.2 Reset players ability
    for (int i = 0; i < 7; i++)
    {
        if (!this->players->getElmt(i).getIsDisable())
        {
            this->players->getElmt(i).setIsDisable();
        }
    }

    // 3. Initialize deck
    initializePlayingDeck();

    // 4. Roll playing cards
    rollPlayingCard();

    // 5. Initialize ability
    initializeAbilityDeck();

    // 6. Roll ability
    rollAbility();
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
        // for (int i = 0; i < this->playingDeck->getLength(); i++)
        // {
        //     this->playingDeck->getElmt(i).displayCard();
        //     std::cout << " ";
        // }
        // std::cout << std::endl;
        // std::cout << this->playingDeck->getLength() << std::endl;
        std::cout << "\n#-----=========== PLAYER TURN ===========-----#\n"
                  << std::endl;
        std::cout << "Name:\t" << this->players->getElmt(0).getName() << std::endl;
        std::cout << "Points:\t" << this->players->getElmt(0).getPoints() << std::endl;
        std::cout << "Hands:\t";
        this->players->getElmt(0).displayHands();
        std::cout << std::endl;
        this->players->getElmt(0).findCombo(*table);
        std::cout << "Combo:\t" << this->players->getElmt(0).getHighestCombo()->getName();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Action menu:" << std::endl;
        std::cout << "1. Double" << std::endl;
        std::cout << "2. Next" << std::endl;
        std::cout << "3. Half" << std::endl;
        std::cout << "4. ";
        std::cout << this->playersAbility[this->players->getElmt(0).getName()]->getName();
        // this->players->getElmt(0).setIsDisable();
        std::cout << " [Ability]";
        if (this->players->getElmt(0).getIsDisable())
        {
            std::cout << " [Not available]";
        }
        std::cout << std::endl;
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
                if (this->players->getElmt(0).getIsDisable())
                {
                    throw ActionException();
                }
                this->setPrize(this->playersAbility[this->players->getElmt(0).getName()]->use(this->prize));
                this->playersAbility[this->players->getElmt(0).getName()]->use(*this->players, *this->playingDeck, this->turn);
                this->players->getElmt(0).setIsDisable();
            }
            else
            {
                throw ActionException();
            }
            isValid = true;
        }
        catch (ActionException err)
        {
            errMsg = err.what();
        }
    }
}