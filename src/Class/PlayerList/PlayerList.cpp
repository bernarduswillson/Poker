#include "PlayerList.hpp"

// === CONSTRUCTOR DESTRUCTOR ==================================

PlayerList::PlayerList() : InventoryHolder() {}

PlayerList::~PlayerList() {}

// === GETTER ==================================================

int PlayerList::getLength()
{
    return this->length;
}

Player PlayerList::getElmt(int index)
{
    return this->buffer[index];
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
