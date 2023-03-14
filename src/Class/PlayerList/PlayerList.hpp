#ifndef __PLAYER_LIST_HPP__
#define __PLAYER_LIST_HPP__

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Player/Player.hpp"

class PlayerList : virtual public InventoryHolder
{
private:
    std::vector<Player> buffer;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    PlayerList();
    ~PlayerList();

    // === GETTER ==================================================
    int getLength() override;
    Player getElmt(int);

    // === INSERT ==================================================
    void push(const Player &);
    void setPlayerCards(int, std::vector<Card>);

    // === METHODS =================================================
    void roundRobin();
};

#endif