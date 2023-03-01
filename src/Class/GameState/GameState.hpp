#ifndef __GAME_STATE_HPP__
#define __GAME_STATE_HPP__

#include <vector>

#include "../PlayerList/PlayerList.hpp"
#include "../Deck/Deck.hpp"
#include "../Card/Card.hpp"
#include "../Ability/Ability.hpp"

class GameState
{
private:
    int game;
    int round;
    PlayerList *playerList;
    Deck<Card> *cardDeck;
    Deck<Ability> *abilityDeck;
    std::vector<Card> *tableCard;
    int prize;
    bool isGameOver;

public:
    GameState();
    ~GameState();
};

#endif