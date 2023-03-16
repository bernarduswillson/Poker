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
    void operator=(PlayerList &);
    ~PlayerList();

    // === GETTER SETTER ===========================================
    int getLength() override;
    Player &getElmt(int);
    void setElmt(int, Player);

    // === INSERT ==================================================
    void push(const Player &);
    void setPlayerCards(int, std::vector<Card>);

    // === METHODS =================================================
    void roundRobin();
};

#endif