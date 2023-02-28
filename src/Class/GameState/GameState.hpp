#include <iostream>

class GameState {
    private:
        int game;
        int round;
        int deck;
        int players;
        int tableCard;
        int prize;
        int isGameOver;
    public:
        GameState();
        void rollCard();
        void rollAbility();
        void multiplyPrize();
        void setIsGameOver();
        void nextRound();
        void nextGame();
        void gameFinished();
};
