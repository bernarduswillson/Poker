#ifndef __INVENTORY_HOLDER_HPP__
#define __INVENTORY_HOLDER_HPP__

#include <vector>

class InventoryHolder
{
protected:
    int length;

public:
    // === CONSTRUCTOR DESTRUCTOR ==================================
    InventoryHolder();
    ~InventoryHolder();

    // === GETTER ==================================================
    virtual int getLength() = 0;
};

#endif