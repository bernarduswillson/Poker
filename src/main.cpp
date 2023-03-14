#include <iostream>

#include "./Class/GameState/GameState.hpp"

int main()
{
    // INITIALIZE GAME =============================================
    GameState *gameState = new GameState();

    // START GAME ==================================================
    gameState->displaySplash();
    gameState->newGame();

    gameState->displayGameState();
    gameState->displayTable();
    gameState->playerAction();
    // Card c(5, 0);
    // std::cout << c << std::endl;

    // CLEAR MEMORY ================================================
    delete gameState;

    // return 0;
}
