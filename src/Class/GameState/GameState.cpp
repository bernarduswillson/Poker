#include "GameState.hpp"

GameState::GameState()
{
    this->game = 1;
    this->round = 1;

    // Initialize empty player list
    this->playerList = new PlayerList();

    // Initialize empty card deck
    this->cardDeck = new Deck<Card>;

    // Initialize empty ability deck
    this->abilityDeck = new Deck<Ability>;

    // Initialize empty table card
    this->tableCard = new std::vector<Card>;

    // Initialize prize
    this->prize = 64;

    this->isGameOver = false;
}

GameState::~GameState()
{
    delete this->playerList;
    delete this->cardDeck;
    delete this->abilityDeck;
    delete this->tableCard;
}