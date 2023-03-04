#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include "../PlayerList/PlayerList.hpp"

class GameState
{
private:
    int game;
    int round;
    int prize;
    int turn;
    PlayerList *players;
    // PlayerList players;

public:
    GameState();
    ~GameState();

    void displaySplash();
    void displayGameState();
    void displayLeaderboard();
    void startNewGame();
    void initializePlayers();
};

#endif