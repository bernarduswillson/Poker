#include <iostream>

#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->displaySplash();
    gameState->newGame();

    // gameState->displayGameState();

    // CLEAR MEMORY ================================================
    delete gameState;

    // return 0;
}