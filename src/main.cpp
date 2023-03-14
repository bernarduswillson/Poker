#include <iostream>

#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->displaySplash();
    gameState->newGame();

    for (int round = 1; round < 7; round++)
    {
        for (int turn = 1; turn < 8; turn++)
        {
            gameState->displayGameState();
            gameState->displayTable();
            gameState->playerAction();
            gameState->nextTurn();
        }
        gameState->nextRound();
    }

    // CLEAR MEMORY ================================================
    delete gameState;

    // return 0;
}
