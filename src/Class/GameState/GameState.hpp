#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <vector>
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
    GameState();
    ~GameState();

    void displaySplash();
    void displayGameState();
    void displayLeaderboard();
    void startNewGame();
    void initializePlayers();
};

#endif