#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <iostream>

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Player/Player.hpp"

class GameState
{
private:
    int game;
    int round;
    long long int prize;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    GameState();
    ~GameState();

    // === DISPLAY =================================================
    void displaySplash();
    void displayGameState();

    // === GAME CONTROL ============================================
    void newGame();
    void nextRound();
    void nextGame();
};

#endif