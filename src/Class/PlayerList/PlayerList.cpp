#include "PlayerList.hpp"

#include <iostream>

// === CONSTRUCTOR DESTRUCTOR ==================================

PlayerList::PlayerList() : InventoryHolder() {}

void PlayerList::operator=(PlayerList &other)
{
    this->buffer = other.buffer;
}

PlayerList::~PlayerList() {}

// === GETTER SETTER ===========================================

int PlayerList::getLength()
{
    return this->length;
}

Player &PlayerList::getElmt(int index)
{
    return this->buffer[index];
}

void PlayerList::setElmt(int index, Player newPlayer)
{
    this->buffer[index] = newPlayer;
}

// === INSERT ==================================================

void PlayerList::push(const Player &player)
{
    this->buffer.push_back(player);
    this->length++;
}

void PlayerList::setPlayerCards(int idx, std::vector<Card> cards)
{
    this->buffer[idx].setHands(cards);
}

// === METHODS =================================================
void PlayerList::roundRobin()
{
    Player temp = this->buffer[0];
    std::vector<Player>::iterator itr = this->buffer.begin();
    this->buffer.erase(itr);
    this->buffer.push_back(temp);
}
