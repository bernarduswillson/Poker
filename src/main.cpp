

#include <iostream>

#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->displaySplash();
    gameState->newGame();

    // GAME ONGOING ================================================
    while (gameState->isOngoing())
    {
        for (int round = 1; round < 7; round++)
        {
            for (int turn = 1; turn < 8; turn++)
            {
                gameState->playerAction();
                gameState->nextTurn();
            }
            gameState->nextRound();
        }
        gameState->nextGame();
    }

    // GAME FINISHED ===============================================
    gameState->displayWinner();

    // CLEAR MEMORY ================================================
    delete gameState;

    // return 0;
}