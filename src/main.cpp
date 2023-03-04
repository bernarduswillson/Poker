#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->startNewGame();

    // CLEAR MEMORY ================================================
    delete gameState;

    return 0;
}