#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->newGame();
    gameState->displaySplash();

    gameState->displayGameState();

    // CLEAR MEMORY ================================================
    delete gameState;

    // return 0;
}