#include "PlayerList.hpp"

PlayerList::PlayerList() : InventoryHolder()
{
}

PlayerList::~PlayerList() {}

int PlayerList::getLength()
{
    return this->length;
}

Player PlayerList::getElmt(int index)
{
    return this->buffer[index];
}
