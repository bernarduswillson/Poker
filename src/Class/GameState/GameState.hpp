#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <iostream>

#include "../PlayerList/PlayerList.hpp"
#include "../Player/Player.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"
#include "../Table/Table.hpp"

class GameState
{
private:
    int game;
    int round;
    long long int prize;
    long long int target;
    bool ongoing;
    PlayerList *players;
    Deck<Card> *playingDeck;
    Table *table;
    Player winner;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    GameState();
    ~GameState();

    // === GETTER SETTER ===========================================
    bool isOngoing();

    // === DISPLAY =================================================
    void displaySplash();
    void displayGameState();
    void displayTable();
    void displayWinner();

    // === INITIALIZER =============================================
    void initializePlayer();
    void initializePlayingDeck();
    void randomizeDeck();
    void rollPlayingCard();
    void evaluateGameWinner();

    // === GAME CONTROL ============================================
    void newGame();
    void nextTurn();
    void nextRound();
    void nextGame();
    void playerAction();
};

#endif