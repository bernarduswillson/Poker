#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <iostream>
#include <vector>
#include <string>
#include "../PlayerList/PlayerList.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"

class GameState
{
private:
    int game;
    int round;
    int prize;
    int turn;
    PlayerList *players;
    Deck<Card> *playingDeck;
    std::vector<Card> table;

public:
    // Constructor and Destructor
    GameState();
    ~GameState();

    // Methods
    void displaySplash();
    void displayGameState();
    void displayLeaderboard();
    void displayTable();
    void displayPlayer();

    void startNewGame();
    void startNewRound();
    void initializePlayers();
    void initializeDeck();
    void initializeRandomDeck();
    void roll();
    void rollTable();

    void nextTurn();
    void nextRound();

    void playerAction();
};

#endif