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
    PlayerList *players;
    Deck<Card> *playingDeck;
    Table *table;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    GameState();
    ~GameState();

    // === DISPLAY =================================================
    void displaySplash();
    void displayGameState();
    void displayTable();

    // === INITIALIZER =============================================
    void initializePlayer();
    void initializePlayingDeck();
    void randomizeDeck();

    // === GAME CONTROL ============================================
    void newGame();
    void nextRound();
    void nextGame();
};

#endif