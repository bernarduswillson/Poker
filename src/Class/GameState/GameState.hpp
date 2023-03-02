#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

class GameState
{
private:
    int game;
    int round;
    int prize;
    // PlayerList players;

public:
    GameState();
    ~GameState();

    void displayGameState();
    void initializePlayers();
    void displayLeaderboard();
};

#endif