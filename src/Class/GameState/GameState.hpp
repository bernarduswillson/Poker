#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "../PlayerList/PlayerList.hpp"
#include "../Player/Player.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"
#include "../Table/Table.hpp"
#include "../Ability/Ability.hpp"
#include "../Multiplier/Multiplier.hpp"
#include "../PlayerManipulation/PlayerManipulation.hpp"

#include "../PlayerList/PlayerList.hpp"
#include "../Player/Player.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"
#include "../Table/Table.hpp"

class GameState
{
private:
    int game;
    int round;
    long long int prize;
    long long int target;
    bool ongoing;
    PlayerList *players;
    Deck<Card> *playingDeck;
    Deck<Ability *> *abilityDeck;
    std::map<std::string, Ability *> playersAbility;
    Table *table;
    Player winner;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    GameState();
    ~GameState();

    // === GETTER SETTER ===========================================
    void setPrize(long long int);
    long long int getPrize();
    bool isOngoing();

    // === DISPLAY =================================================
    void displaySplash();
    void displayGameState();
    void displayTable();
    void displayWinner();

    // === INITIALIZER =============================================
    void initializePlayer();
    void initializePlayingDeck();
    void randomizeDeck();
    void generateDeckTxt();
    void rollPlayingCard();
    void initializeAbilityDeck();
    void rollAbility();
    void evaluateGameWinner();

    // === GAME CONTROL ============================================
    void newGame();
    void nextTurn();
    void nextRound();
    void nextGame();
    void playerAction();
};

#endif