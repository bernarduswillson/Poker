#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <vector>
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"

class Table : virtual public InventoryHolder
{
private:
    std::vector<Card> buffer;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    Table();
    ~Table();

    // === GETTER ==================================================
    int getLength();
    Card getElmt(int);
    std::vector<Card> getBuffer();

    // === DISPLAY =================================================
    void display(int);

    // === METHODS =================================================
    void push(Card);
    Card pop();
};

#endif